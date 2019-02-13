#include "CloseCombat1.h"

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
