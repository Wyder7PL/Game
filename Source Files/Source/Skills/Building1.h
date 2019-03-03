#pragma once
#include "NonCombatSkill.h"
#include "BuildOrder.h"
#include "../Items/Tools/ConstructionTool.h"
#include "../projectile/Tool-projectile/SCM.h"
#include "Dereserve.h"

class Building1:public NonCombatSkill
{
    BuildOrder order;
    Info * magasine;
    uint32_t GoToMagasine(ConstructionTool*,Info*,Position);
public:
    Building1();
    virtual ~Building1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
};
