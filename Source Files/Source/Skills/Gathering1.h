#pragma once
#include "NonCombatSkill.h"
#include "../Items/Tools/GatherTool.h"

class Gathering1:public NonCombatSkill
{
    bool FocusedOnResource;
    bool FocusedOnMagazine;
    uint32_t FocusedID;

public:
    Gathering1();
    virtual ~Gathering1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
};
