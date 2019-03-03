#include "HP.h"

HP::HP(uint32_t Max,uint32_t current)
{
    if(current == 0)
        hp = Max;
    else
        hp = current;
    full = Max;
}

HP::~HP()
{
    //dtor
}

void HP::Step(){}

void HP::TakeDamage(uint32_t damage,uint32_t type)
{
    hp -= damage;
}

int32_t HP::GetHP()
{
    return hp;
}
int32_t HP::GetMaxHP()
{
    return full;
}
