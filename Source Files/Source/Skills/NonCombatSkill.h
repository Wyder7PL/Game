#pragma once
#include "Skill.h"

class NonCombatSkill:public Skill
{
protected:
    bool WorkCaneled;
    bool WorkAborted;
public:
    NonCombatSkill();
    void CanelWork(bool);
    void AbortWork(bool);
};
