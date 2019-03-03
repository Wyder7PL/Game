#include "Shooting1.h"

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
