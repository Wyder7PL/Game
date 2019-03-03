#include "MainControler.hpp"

mainControler::mainControler()
{
    Graphic.SetView(0,0);
}

mainControler::~mainControler()
{
    DestroyElements();
}

void mainControler::DestroyElements()
{
    for(std::vector <Object*>::iterator ite = Objects.begin();ite != Objects.end();ite++)
        delete (*ite);
    Objects.clear();
    for(std::list <EffectObject*>::iterator ite = Effects.begin();ite != Effects.end();ite++)
        delete (*ite);
    Effects.clear();
}

void mainControler::Step()
{
    Physic.ClearArray();
    Graphic.ClearArray();

    Graphic.SetKeyboard();

    Clear();

    SortArrays();
    ApplyEffects();


    Physic.MaskSort();
    SymulatePhysicAndEffectsCollision();

    EffectsLastWish();

    AddObjects();

    Graphic.DrawEverything();
}

void mainControler::CreateObject(Object * obj)
{
    Graphic.TESTCreateGraphic(obj);
    Physic.TESTaddPhysic(obj);
    Objects.push_back(obj);
}

void mainControler::CreateEffect(EffectObject * obj)
{
    Effects.push_back(obj);
}

void mainControler::Clear()
{
    for(std::vector <Object*>::iterator ite = Objects.begin();ite != Objects.end();)
    {
        if((*ite)->IsDestroyed())
        {
            delete (*ite);
            ite = Objects.erase(ite);
        }
        else if((*ite)->IsDesactivated())
            ite = Objects.erase(ite);
        else
        {
            (*ite)->Step();
            ite++;
        }
    }
    for(std::list <EffectObject*>::iterator ite = Effects.begin();ite != Effects.end();)
    {
        if((*ite)->IsToClear())
        {
            delete (*ite);
            ite = Effects.erase(ite);
        }
        else
            ite++;
    }
}

void mainControler::SortArrays()
{
    sort(Objects.begin(),Objects.end(),ObjectComparison);
    uint32_t i = 0;
    for(std::vector <Object*>::iterator ite = Objects.begin();ite != Objects.end();ite++)
    {
        (*ite)->VectorID = i;
        i++;
    }
    Effects.sort([](EffectObject * a, EffectObject * b) {return(a->AffectedID() < b->AffectedID());});
}

void mainControler::ApplyEffects()
{
    uint32_t O = 0,E = 0;
    std::vector <Object*>::iterator ite2 = Objects.begin();
    for(std::list <EffectObject*>::iterator ite = Effects.begin();ite != Effects.end();)
    {
        if(ite2 == Objects.end())
        {
            do{
                (*ite)->SetToClear();
                ite++;
            }while(ite != Effects.end());
            continue;
        }
        else if((*ite)->AffectedID() > (*ite2)->GetID())
        {
            bool stay;
            do{
                stay = false;
                ite2++;O++;
                if(ite2 == Objects.end())
                {
                    stay = false;
                    ite++;
                }
                else if((*ite)->AffectedID() > (*ite2)->GetID())
                    stay = true;
            }while(stay);
            continue;
        }
        else if((*ite)->AffectedID() < (*ite2)->GetID())
        {
            bool stay;
            do{
                stay = false;
                (*ite)->SetToClear();
                ite++;E++;
                if(ite == Effects.end())
                    stay = false;
                else if((*ite)->AffectedID() < (*ite2)->GetID())
                    stay = true;
            }while(stay);
            continue;
        }
        else
        {
            (*ite)->Step(Inserter,(*ite2));
            ite++;E++;
        }
    }
}

void mainControler::SymulatePhysicAndEffectsCollision()
{
    Physic.SimulatePhysicV2();
    if(Physic.Collisions.size()>0)
    {
        for(std::list <EffectObject*>::iterator ite = Effects.begin();ite != Effects.end();ite++)
        {
            for(std::list <uint32X2>::iterator ite2 = Physic.Collisions.begin();ite2 != Physic.Collisions.end();ite2++)
            {
                if( (*ite)->AffectedID() == Objects[(*ite2).X]->GetID())
                    (*ite)->OnCollision(Inserter,Objects[(*ite2).Y]);
                else if( (*ite)->AffectedID() == Objects[(*ite2).Y]->GetID())
                    (*ite)->OnCollision(Inserter,Objects[(*ite2).X]);
            }
        }
    }

}

void mainControler::EffectsLastWish()
{
    for(std::list <EffectObject*>::iterator ite = Effects.begin();ite != Effects.end();ite++)
    {
        if((*ite)->IsToClear())
            (*ite)->OnDestroy(Inserter);
    }
}

void mainControler::AddObjects()
{
    for(std::list <Object*>::iterator ite = Inserter.Objects.begin();ite != Inserter.Objects.end();ite++)
    {
        CreateObject((*ite));
    }
    for(std::list <EffectObject*>::iterator ite = Inserter.Effects.begin();ite != Inserter.Effects.end();ite++)
    {
       CreateEffect((*ite));
    }
    Inserter.Objects.clear();
    Inserter.Effects.clear();
}
