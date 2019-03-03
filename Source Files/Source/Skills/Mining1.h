#pragma once
#include "NonCombatSkill.h"
#include "../Items/Tools/MiningTool.h"

class Mining1:public NonCombatSkill
{
    bool FocusedOnWorkPlace;
    bool FocusedOnMagazine;
    uint32_t FocusedID;
    uint32_t FocusedSlot;
public:
    Mining1();
    virtual ~Mining1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
};
