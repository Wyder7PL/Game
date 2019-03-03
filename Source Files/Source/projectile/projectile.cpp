#include "projectile.h"

projectile::projectile(Position pos,uint32_t f):Object(pos),fractions(f){SetZIndex(6);}
projectile::~projectile(){}
uint32_t projectile::GetFractions()
{
    return fractions;
}
void projectile::SetFractions(uint32_t f)
{
    fractions = f;
}
