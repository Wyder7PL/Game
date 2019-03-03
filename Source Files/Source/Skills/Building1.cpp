#include "Building1.h"

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
