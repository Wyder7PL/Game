#pragma once
#include "NonCombatSkill.h"
#include "../Items/Tools/ToolBox.h"

class Working1:public NonCombatSkill
{
    bool FocusedOnWorkPlace;
    bool FocusedOnMagazine;
    uint32_t FocusedID;
    uint32_t FocusedSlot;
    uint32_t FocusedResourceID;
    uint32_t FocusedMagazineID;
public:
    Working1();
    virtual ~Working1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
private:
    bool checktypedynamiccast(Item **,uint32_t);
};
