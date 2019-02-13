#include "Mining1.h"

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
