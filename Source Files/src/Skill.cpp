#include "../include/Skill.h"

Skill::Skill()
:destination(0,0),speedModyhicator(1.0),ChangegMass(0)
{
    SlotAddres = NULL;
}

Skill::~Skill()
{
    //dtor
}

Position Skill::Destination()
{
    return destination;
}
Slot * Skill::GetSlot()
{
    return SlotAddres;
}

float Skill::Speed()
{
    return speedModyhicator;
}

void Skill::ChangeFraction(uint32_t f)
{
    fractions = f;
}

uint32_t Skill::GetSkillType()
{
    return 0;
}

float Skill::GetChangedMass()
{
    float tmp = ChangegMass;
    ChangegMass = 0;
    return tmp;
}

CloseCombat1::CloseCombat1(){}
CloseCombat1::~CloseCombat1(){}
uint32_t CloseCombat1::Step(Position pos,std::list<Item**>* items,std::list<Info>* objects)
{
    CloseCombatItem * cci = NULL;
    for(std::list <Item**>::iterator ite = items->begin();ite!=items->end();ite++)
    {
        if(dynamic_cast<CloseCombatItem*>(*(*ite))!=NULL)
        {
            cci = dynamic_cast<CloseCombatItem*>(*(*ite));
            break;
        }
    }
    if(cci!=NULL)
    {
        for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
        {
            if((*ite).type < 100 &&(*Fraction::Fractions)[fractions]->CompareFractions((*ite).fraction)==0)
            {
                PhysicShape * shap;
                if((*ite).shapetype==1)
                    shap = new Circle((*ite).shapesize.GetX());
                bool result = cci->Attack(pos,shap->GetClosestEdge(pos,(*ite).position,0.5));
                delete shap;
                if(result)
                    return 3;
                destination = (*ite).position;
                speedModyhicator = 1;
                return 1;
            }
        }
    }
    return 0;
}
uint32_t CloseCombat1::GetSkillType()
{
    return 3;
}

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

Shooting1::Shooting1(){}
Shooting1::~Shooting1(){}
uint32_t Shooting1::Step(Position pos,std::list<Item**>* items,std::list<Info>* objects)
{
    SingleShot * cci = NULL;
    for(std::list <Item**>::iterator ite = items->begin();ite!=items->end();ite++)
    {
        if(dynamic_cast<SingleShot*>(*(*ite))!=NULL)
        {
            cci = dynamic_cast<SingleShot*>(*(*ite));
            break;
        }
    }
    if(cci!=NULL)
    {
        Info * i = NULL;
        float distance = 10000;
        for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
        {
            if((*ite).type < 100&&(*Fraction::Fractions)[fractions]->CompareFractions((*ite).fraction)==0 && pos.distance((*ite).position) < distance)
            {
                distance = pos.distance((*ite).position);
                i = &(*ite);
            }
        }
        if(i!=NULL)
        {
            if(cci->Shoot(pos,i->position))
                return 3;
            if(cci->GetActualReload()>0)
            {
                cci->Reload(100);
                return 3;
            }
            destination = i->position;
            speedModyhicator = 1;
                return 1;
        }
    }

    return 0;
}
uint32_t Shooting1::GetSkillType()
{
    return 5;
}

BuildOrder::BuildOrder():pos(0,0),Type(0),Hits(0){}

Dereserve::Dereserve(uint32_t id,uint32_t type,uint32_t amount)
:SCMEff(0,id),Rtype(type),Amount(amount){}
Dereserve::~Dereserve(){}
void Dereserve::Communicate(Object * obj)
{
    Construction * con = dynamic_cast<Construction*>(obj);
    if(con!=NULL)
    {
        con->Dereserve(Rtype,Amount);
    }
}

NonCombatSkill::NonCombatSkill():WorkCaneled(false),WorkAborted(false){}
void NonCombatSkill::CanelWork(bool w){WorkCaneled = w;}
void NonCombatSkill::AbortWork(bool w){WorkAborted = w;}

Building1::Building1(){}
Building1::~Building1()
{
    if(order.ordered)
    {
        (*Fraction::Fractions)[fractions]->GetEco()->GEE(order.Type)->UnReserve(order.Hits);
        SCM * scm = new SCM(new Dereserve(order.TargetID,order.Type,order.Hits),fractions);
        AddObject add;
        add.Add(scm);
    }
}
uint32_t Building1::Step(Position pos,std::list<Item**>* items,std::list<Info>* objects)
{
    if(WorkCaneled||WorkAborted)
    {
        if(WorkAborted&&order.ordered)
        {
            order.ordered = false;
            (*Fraction::Fractions)[fractions]->GetEco()->GEE(order.Type)->UnReserve(order.Hits);
            SCM * scm = new SCM(new Dereserve(order.TargetID,order.Type,order.Hits),fractions);
            AddObject add;
            add.Add(scm);
        }
        return 0;
    }
    ConstructionTool * t = NULL;
    magasine = NULL;
    for(std::list <Item**>::iterator ite = items->begin();ite!=items->end();ite++)
    {
        if(dynamic_cast<ConstructionTool*>(*(*ite))!=NULL)
        {
            t = dynamic_cast<ConstructionTool*>(*(*ite));
            break;
        }
    }
    if(t!=NULL)
    {
        if(order.ordered)
        {
            for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
            {
                if((*ite).id == order.TargetID)
                {
                    PhysicShape * shap;
                    if((*ite).shapetype==1)
                        shap = new Circle((*ite).shapesize.GetX());
                    uint32_t result = t->Build(pos,shap->GetClosestEdge(pos,(*ite).position,0.5));
                    delete shap;
                    switch(result)
                    {
                    case 0:
                        {
                            destination = (*ite).position;
                            speedModyhicator = 1;
                            return 1;
                        }
                    case 1:
                        {
                            return 0;
                        }
                    case 2:
                        {
                            order.Hits--;
                            if(order.Hits == 0)
                            {
                                order.ordered = false;
                            }
                            return 0;
                        }
                    }
                }
            }
            if(Fraction::Fractions != NULL && Fraction::Fractions->size() > fractions)
            {
                order.ordered = false;
                (*Fraction::Fractions)[fractions]->GetEco()->GEE(order.Type)->UnReserve(order.Hits);
            }
        }
        else
        {
            bool busy = false;
            float distancetomagasine = 10000;
            if(Fraction::Fractions == NULL || Fraction::Fractions->size() <= fractions)
                return 0;
            for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
            {
                if( (*ite).fraction==fractions && (*ite).type == 2 && (*ite).lpointer != NULL)
                {
                    if((*ite).lpointer->DestroyMe())
                            continue;
                    for(std::list <void*>::iterator ite2 = (*ite).lpointer->GetPointer()->begin();
                    ite2!=(*ite).lpointer->GetPointer()->end();ite2++)
                    {
                        ResourceDemand * RD = reinterpret_cast<ResourceDemand*>((*ite2));
                        uint32_t Rtype = RD->GetID();
                        if((*ResourceStorage::ResourcesList)[Rtype]->build != NULL)
                        {
                        uint32_t Rprice = (*ResourceStorage::ResourcesList)[Rtype]->build->buildcost;
                        while(t->GetWorkPoints() >= Rprice && RD->GetNonReserved() > 0 &&
                        (*Fraction::Fractions)[fractions]->GetEco()->GEE(Rtype)->GetNonReservedAmount()
                              > 0)
                        {
                            RD->Reserve(1);
                            (*Fraction::Fractions)[fractions]->GetEco()->GEE(Rtype)->Reserve(1);
                            t->SetWorkPoints(t->GetWorkPoints()-Rprice);
                            t->SetType(Rtype);
                            order.Hits++;
                            busy = true;
                        }
                        if(busy)
                        {
                            order.ordered = true;
                            order.TargetID = (*ite).id;
                            order.pos = (*ite).position;
                            order.Type = Rtype;
                            return 0;
                        }
                        }
                    }
                }
                else if((*ite).type == 3 && (*ite).fraction==fractions && pos.distance((*ite).position) < distancetomagasine)
                {
                    distancetomagasine = pos.distance((*ite).position);
                    magasine = &(*ite);
                }
            }
            if(magasine != NULL && t->GetWorkPoints() < t->GetMaxWorkPoints())
            {
                PhysicShape * shap;
                if(magasine->shapetype==1)
                    shap = new Circle(magasine->shapesize.GetX());
                bool result = t->Refill(pos,shap->GetClosestEdge(pos,magasine->position,0.5));
                delete shap;
                if(result)
                    return 0;
                destination = magasine->position;
                speedModyhicator = 1;
                return 1;
            }
        }

    }
    return 0;
}

uint32_t Building1::GoToMagasine(ConstructionTool* t,Info* magasine,Position pos)
{
    PhysicShape * shap;
    if(magasine->shapetype==1)
        shap = new Circle(magasine->shapesize.GetX());
    bool result = t->Refill(pos,shap->GetClosestEdge(pos,magasine->position,0.5));
    delete shap;
    if(result)
        return 0;
    destination = magasine->position;
    speedModyhicator = 1;
    return 1;
}

Gathering1::Gathering1():FocusedOnResource(false),FocusedOnMagazine(false){}
Gathering1::~Gathering1(){}

uint32_t Gathering1::Step(Position pos,std::list<Item**>* items,std::list<Info>* objects)
{
    if(WorkCaneled||WorkAborted)
    {
        if(WorkAborted&&(FocusedOnResource||FocusedOnMagazine))
        {
            FocusedOnResource = false;
            FocusedOnMagazine = false;
            FocusedID = 0;
        }
        return 0;
    }
    GatherTool * g = NULL;
    Item ** i = NULL;
    bool EmptyHand = false;
    for(std::list <Item**>::iterator ite = items->begin();ite!=items->end();ite++)
    {
        if(dynamic_cast<GatherTool*>(*(*ite))!=NULL)
            g = dynamic_cast<GatherTool*>(*(*ite));
        else
        {
            if(*(*ite)==NULL)
                EmptyHand = true;
            i = (*ite);
        }
    }
    if(g!=NULL)
    {
        if(EmptyHand)
        {
            Info * inf = NULL;
            float distance = 10000;
            if(FocusedOnResource)
            {
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).id==FocusedID)
                    {inf = &(*ite);break;}
                }
            }
            if(inf == NULL)
            {
                FocusedOnResource = false;
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).type == 101/*g->gatheredType*/ && pos.distance((*ite).position) < distance)
                    {
                        inf = &(*ite);
                        FocusedOnResource = true;
                        FocusedID = (*ite).id;
                        distance = pos.distance((*ite).position);
                    }
                }
            }
            if(inf!=NULL)
            {
                PhysicShape * shap;
                if(inf->shapetype==1)
                    shap = new Circle(inf->shapesize.GetX());
                uint32_t result = g->Gather(pos,shap->GetClosestEdge(pos,inf->position,0.5),inf->id);
                delete shap;
                switch(result)
                {
                case 0:
                    {
                        destination = inf->position;
                        speedModyhicator = 1;
                        return 1;
                    }
                case 1:
                    {
                        return 0;
                    }
                case 2:
                    {
                        *i = new ResourceItem(fractions,Material(wood));
                        FocusedOnResource = false;
                        return 0;
                    }
                }
            }
        }
        else if(dynamic_cast<ResourceItem*>(*i))
        {
            Info * inf = NULL;
            float distance = 10000;
            if(FocusedOnMagazine)
            {
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).id==FocusedID)
                    {inf = &(*ite);break;}
                }
            }
            if(inf == NULL)
            {
                FocusedOnMagazine = false;
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).type == 3/*g->gatheredType*/ && (*ite).fraction == fractions && pos.distance((*ite).position) < distance)
                    {
                        inf = &(*ite);
                        FocusedOnMagazine = true;
                        FocusedID = (*ite).id;
                        distance = pos.distance((*ite).position);
                    }
                }
            }
            if(inf!=NULL)
            {
                ResourceItem * rei = dynamic_cast<ResourceItem*>(*i);
                PhysicShape * shap;
                if(inf->shapetype==1)
                    shap = new Circle(inf->shapesize.GetX());
                uint32_t result = g->Store(pos,shap->GetClosestEdge(pos,inf->position,0.5),rei->GetType(),1);
                delete shap;
                switch(result)
                {
                case 0:
                    {
                        destination = inf->position;
                        speedModyhicator = 1;
                        return 1;
                    }
                case 1:
                    {
                        FocusedOnMagazine = false;
                        delete *i;
                        *i=NULL;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

/// ////// ///
/// Mining ///
/// ////// ///

Mining1::Mining1():FocusedOnWorkPlace(false),FocusedOnMagazine(false){}
Mining1::~Mining1(){}

uint32_t Mining1::Step(Position pos,std::list<Item**>* items,std::list<Info>* objects)
{
    if(WorkCaneled||WorkAborted)
    {
        if(WorkAborted&&(FocusedOnWorkPlace||FocusedOnMagazine))
        {
            FocusedOnWorkPlace = false;
            FocusedOnMagazine = false;
            FocusedID = 0;
            FocusedSlot = 0;
        }
        return 0;
    }
    MiningTool * m = NULL;
    Item ** i = NULL;
    bool EmptyHand = false;
    for(std::list <Item**>::iterator ite = items->begin();ite!=items->end();ite++)
    {
        if(dynamic_cast<MiningTool*>(*(*ite))!=NULL)
            m = dynamic_cast<MiningTool*>(*(*ite));
        else
        {
            if(*(*ite)==NULL)
                EmptyHand = true;
            i = (*ite);
        }
    }
    if(m!=NULL)
    {
        if(EmptyHand)
        {
            Info * inf = NULL;
            Slot * slot = NULL;
            float distance = 10000;
            if(FocusedOnWorkPlace)
            {
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).id==FocusedID)
                    {
                        inf = &(*ite);
                        uint32_t focusedslot = 0;
                        if((*ite).lpointer == NULL||(*ite).lpointer->DestroyMe())
                            continue;
                        for(std::list <void*>::iterator ite2 = (*ite).lpointer->GetPointer()->begin();
                        ite2!=(*ite).lpointer->GetPointer()->end();ite2++)
                        {
                            if(focusedslot==FocusedSlot)
                            {
                                slot = reinterpret_cast<Slot*>((*ite2));
                                break;
                            }
                            focusedslot++;
                        }
                    }
                }
            }
            if(inf == NULL && slot == NULL)
            {
                FocusedOnWorkPlace = false;
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    uint32_t temp = (*ite).type;
                    if((*ite).type == 6 && pos.distance((*ite).position) < distance)
                    {
                        if((*ite).lpointer != NULL){
                           if((*ite).lpointer->DestroyMe())
                            continue;
                        }
                        uint32_t focusedslot = 0;
                        for(std::list <void*>::iterator ite2 = (*ite).lpointer->GetPointer()->begin();
                        ite2!=(*ite).lpointer->GetPointer()->end();ite2++)
                        {
                            Slot * s = reinterpret_cast<Slot*>((*ite2));
                            if(s->Occupant==NULL&&!s->reserved)
                            {
                                inf = &(*ite);
                                s->reserved = true;
                                slot = s;
                                FocusedOnWorkPlace = true;
                                FocusedID = (*ite).id;
                                FocusedSlot = focusedslot;
                                distance = pos.distance((*ite).position);
                            }
                            else
                                focusedslot++;
                        }
                    }
                }
            }
            if(inf!=NULL&&slot!=NULL)
            {
                if(pos.distance(inf->position)<70)
                {
                    FocusedOnWorkPlace = false;
                    SlotAddres = slot;
                    return 2;
                }
                destination = inf->position;
                speedModyhicator = 1;
                return 1;
            }
        }
        else if(dynamic_cast<ResourceItem*>(*i)!=NULL)
        {
            Info * inf = NULL;
            float distance = 10000;
            if(FocusedOnMagazine)
            {
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).id==FocusedID)
                    {inf = &(*ite);break;}
                }
            }
            if(inf == NULL)
            {
                FocusedOnMagazine = false;
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).type == 3 && (*ite).fraction == fractions && pos.distance((*ite).position) < distance)
                    {
                        inf = &(*ite);
                        FocusedOnMagazine = true;
                        FocusedID = (*ite).id;
                        distance = pos.distance((*ite).position);
                    }
                }
            }
            if(inf!=NULL)
            {
                ResourceItem * rei = dynamic_cast<ResourceItem*>(*i);
                PhysicShape * shap;
                if(inf->shapetype==1)
                    shap = new Circle(inf->shapesize.GetX());
                uint32_t result = m->Store(pos,shap->GetClosestEdge(pos,inf->position,0.5),rei->GetType(),1);
                delete shap;
                switch(result)
                {
                case 0:
                    {
                        destination = inf->position;
                        speedModyhicator = 1;
                        return 1;
                    }
                case 1:
                    {
                        FocusedOnMagazine = false;
                        ChangegMass = -((*i)->GetWeight());
                        delete *i;
                        *i=NULL;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

/// /////// ///
/// Working ///
/// /////// ///

Working1::Working1():FocusedOnWorkPlace(false),FocusedOnMagazine(false){}
Working1::~Working1(){}

uint32_t Working1::Step(Position pos,std::list<Item**>* items,std::list<Info>* objects)
{
    if(WorkCaneled||WorkAborted)
    {
        if(WorkAborted&&(FocusedOnWorkPlace||FocusedOnMagazine))
        {
            FocusedOnWorkPlace = false;
            FocusedOnMagazine = false;
            FocusedID = 0;
            FocusedSlot = 0;
        }
        return 0;
    }
    ToolBox * m = NULL;
    Item ** i = NULL;
    bool EmptyHand = false;
    for(std::list <Item**>::iterator ite = items->begin();ite!=items->end();ite++)
    {
        if(dynamic_cast<ToolBox*>(*(*ite))!=NULL)
            m = dynamic_cast<ToolBox*>(*(*ite));
        else
        {
            if(*(*ite)==NULL)
                EmptyHand = true;
            i = (*ite);
        }
    }
    if(m!=NULL)
    {
        Info * inf = NULL;
        Slot * slot = NULL;
        float distance = 10000;

        if(FocusedOnWorkPlace)
        {
            bool exit = false;
            for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end()&&!exit;)
            {
                if((*ite).id==FocusedID)
                {
                    inf = &(*ite);
                    uint32_t focusedslot = 0;
                    if((*ite).lpointer == NULL||(*ite).lpointer->DestroyMe())
                        continue;
                    std::list <void*>::iterator ite2 = (*ite).lpointer->GetPointer()->begin();
                    std::list <Slot> * s = &(*(reinterpret_cast<std::list<Slot>*>((*ite2))));
                    for(std::list <Slot>::iterator ite3 = s->begin();ite3!=s->end()&&!exit;)
                    {
                        if(focusedslot==FocusedSlot)
                        {
                            std::list <ResourceDemand> * rd = &(*(reinterpret_cast<std::list<ResourceDemand>*>(*(++ite2))));
                            for(std::list <ResourceDemand>::iterator ite4 = rd->begin();ite4 != rd->end();ite4++)
                            {
                                if((*ite4).GetID()==FocusedResourceID)
                                {
                                    slot = &(*ite3);
                                    distance = pos.distance((*ite).position);
                                    exit = true;
                                    break;
                                }
                            }
                        }
                        if(ite3!=s->end())
                            ite3++;
                        focusedslot++;
                    }}
                if(ite!=objects->end())
                    ite++;
            }
            if(!exit)
                FocusedOnWorkPlace = false;
        }
        if(!FocusedOnWorkPlace)
        {
            bool exit = false;
            for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end()&&!exit;ite++)
            {
                if((*ite).type == 7 && pos.distance((*ite).position) < distance)
                {
                    if((*ite).lpointer != NULL){
                        if((*ite).lpointer->DestroyMe())
                        continue;}

                    uint32_t focusedslot = 0;
                    std::list <void*>::iterator ite2 = (*ite).lpointer->GetPointer()->begin();
                    std::list <Slot> * s = &(*(reinterpret_cast<std::list<Slot>*>((*ite2))));
                    ite2++;
                    for(std::list <Slot>::iterator ite3 = s->begin();ite3!=s->end()&&!exit;)
                    {
                        if((*ite3).Occupant==NULL&&!(*ite3).reserved)
                        {
                            std::list <ResourceDemand> * rd = reinterpret_cast<std::list<ResourceDemand>*>((*ite2));
                            for(std::list <ResourceDemand>::iterator ite4 = rd->begin();ite4 != rd->end();ite4++)
                            {
                                if((*ite4).GetNonReserved()>0)
                                {
                                    FocusedResourceID = (*ite4).GetID();
                                    ite4 = rd->end();
                                    inf = &(*ite);
                                    slot = &(*ite3);
                                    FocusedOnWorkPlace = true;
                                    FocusedID = (*ite).id;
                                    FocusedSlot = focusedslot;
                                    distance = pos.distance((*ite).position);
                                    exit = true;
                                    break;
                                }
                            }
                        }
                        focusedslot++;
                        if(ite3!=s->end())
                            ite3++;
                    }
                }
            }
        }
    if(FocusedOnWorkPlace){
        if(EmptyHand || !checktypedynamiccast(i,FocusedResourceID))
        {
            distance = 10000;
            Info * MagInf = NULL;
            if(FocusedOnMagazine)
            {
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).id==FocusedMagazineID)
                    {MagInf = &(*ite);break;}
                }
            }
            else
            {
                for(std::list <Info>::iterator ite = objects->begin();ite!=objects->end();ite++)
                {
                    if((*ite).type == 3 && (*ite).fraction == fractions && pos.distance((*ite).position) < distance)
                    {
                        MagInf = &(*ite);
                        FocusedOnMagazine = true;
                        FocusedMagazineID = (*ite).id;
                        distance = pos.distance((*ite).position);
                    }
                }
            }
            if(MagInf!=NULL)
            {
                ResourceItem * rei = dynamic_cast<ResourceItem*>(*i);
                PhysicShape * shap;
                if(MagInf->shapetype==1)
                    shap = new Circle(MagInf->shapesize.GetX());
                uint32_t result=0;
                if(EmptyHand)
                {
                    result = m->Extract(pos,shap->GetClosestEdge(pos,MagInf->position,0.5),FocusedResourceID,1);
                    delete shap;
                    switch(result)
                    {
                    case 0:
                        {
                            destination = MagInf->position;
                            speedModyhicator = 1;
                            return 1;
                        }
                    case 1:{return 0;}
                    case 2:
                        {
                            FocusedOnMagazine = false;
                            *i = m->GetExtractedItem();
                            return 0;
                        }
                    }
                }
                else
                {
                    result = m->Store(pos,shap->GetClosestEdge(pos,MagInf->position,0.5),rei->GetType(),1);
                    delete shap;
                    switch(result)
                    {
                    case 0:
                        {
                            destination = MagInf->position;
                            speedModyhicator = 1;
                            return 1;
                        }
                    case 1:
                        {
                            FocusedOnMagazine = false;
                            ChangegMass = -((*i)->GetWeight());
                            delete *i;
                            *i=NULL;
                            return 0;
                        }
                    }
                }
            }
        }
        else if(inf!=NULL&&slot!=NULL&&checktypedynamiccast(i,FocusedResourceID))
        {
            if(pos.distance(inf->position)<70)
            {
                FocusedOnWorkPlace = false;
                SlotAddres = slot;
                return 2;
            }
            destination = inf->position;
            speedModyhicator = 1;
            return 1;
        }
    }
    }
    return 0;
}

bool Working1::checktypedynamiccast(Item ** i,uint32_t type)
{
    if(dynamic_cast<ResourceItem*>(*i)!=NULL&&dynamic_cast<ResourceItem*>(*i)->GetType()==type)
        return true;
    return false;
}

