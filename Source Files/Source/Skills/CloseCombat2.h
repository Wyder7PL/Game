#pragma once
#include "Skill.h"
#include "../Items/Weapions/CloseCombatItem.h"
#include "../Items/Weapions/SingleShot.h"

class CloseCombat2:public Skill
{
    public:
    CloseCombat2();
    virtual ~CloseCombat2();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
    virtual uint32_t GetSkillType();
};
