#pragma once
#include "Skill.h"
#include "../Items/Weapions/SingleShot.h"

class Shooting1:public Skill
{
public:
    Shooting1();
    virtual ~Shooting1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
    virtual uint32_t GetSkillType();
};
