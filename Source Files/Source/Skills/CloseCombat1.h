#pragma once
#include "Skill.h"
#include "../Items/Weapions/CloseCombatItem.h"

class CloseCombat1:public Skill
{
public:
    CloseCombat1();
    virtual ~CloseCombat1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
    virtual uint32_t GetSkillType();
};
