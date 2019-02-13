#include "Working1.h"

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

