#include "NonCombatSkill.h"

NonCombatSkill::NonCombatSkill():WorkCaneled(false),WorkAborted(false){}

void NonCombatSkill::CanelWork(bool w)
{
    WorkCaneled = w;
}

void NonCombatSkill::AbortWork(bool w)
{
    WorkAborted = w;
}
