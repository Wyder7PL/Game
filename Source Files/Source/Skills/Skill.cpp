#include "Skill.h"

Skill::Skill()
:destination(0,0),speedModyhicator(1.0),ChangegMass(0)
{
    SlotAddres = NULL;
}

Skill::~Skill()
{
    //dtor
}

Position Skill::Destination()
{
    return destination;
}
Slot * Skill::GetSlot()
{
    return SlotAddres;
}

float Skill::Speed()
{
    return speedModyhicator;
}

void Skill::ChangeFraction(uint32_t f)
{
    fractions = f;
}

uint32_t Skill::GetSkillType()
{
    return 0;
}

float Skill::GetChangedMass()
{
    float tmp = ChangegMass;
    ChangegMass = 0;
    return tmp;
}
