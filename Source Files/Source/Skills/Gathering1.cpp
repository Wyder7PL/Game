#include "Gathering1.h"

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
