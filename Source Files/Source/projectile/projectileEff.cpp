#include "projectileEff.h"

projectileEff::projectileEff(){}
projectileEff::~projectileEff(){}
uint32_t projectileEff::GetFractions()
{
    return fractions;
}
void projectileEff::SetFractions(uint32_t f)
{
    fractions = f;
}
