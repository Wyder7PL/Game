#include "CloseCombat2.h"

CloseCombat2::CloseCombat2(){}
CloseCombat2::~CloseCombat2(){}
uint32_t CloseCombat2::Step(Position pos,std::list<Item**>* items,std::list<Info>* objects)
{
    CloseCombatItem * cci = NULL;
    SingleShot * ss = NULL;
    for(std::list <Item**>::iterator ite = items->begin();ite!=items->end();ite++)
    {
        if(dynamic_cast<CloseCombatItem*>(*(*ite))!=NULL)
        {
            cci = dynamic_cast<CloseCombatItem*>(*(*ite));
        }
        if(dynamic_cast<SingleShot*>(*(*ite))!=NULL)
        {
            ss = dynamic_cast<SingleShot*>(*(*ite));
        }
    }
    Info * i = NULL;
        float distance = 10000;
        for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
        {
            if((*ite).type < 100 && (*Fraction::Fractions)[fractions]->CompareFractions((*ite).fraction)==0 && pos.distance((*ite).position) < distance)
            {
                distance = pos.distance((*ite).position);
                i = &(*ite);
            }
        }
        if(i!=NULL)
        {
            if(ss!=NULL)
            {
                if(ss->Shoot(pos,i->position))
                    return 3;
            }
            if(cci!=NULL)
            {
                PhysicShape * shap;
                if(i->shapetype==1)
                    shap = new Circle(i->shapesize.GetX());
                bool result = cci->Attack(pos,shap->GetClosestEdge(pos,i->position,0.5));
                delete shap;
                if(result)
                    return 3;
                destination = i->position;
                speedModyhicator = 1;
                return 1;
            }
        }
    if(ss!=NULL && ss->GetActualReload()>0)
        ss->Reload(100);
    return 0;
}
uint32_t CloseCombat2::GetSkillType()
{
    return 3;
}
