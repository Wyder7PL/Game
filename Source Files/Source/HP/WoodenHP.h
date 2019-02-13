#pragma once

#include "HP.h"


class WoodenHP:public HP
{
    uint32_t FireStrenght;
    uint32_t FireExistance;
public:
    WoodenHP(uint32_t,uint32_t=0);
    virtual ~WoodenHP();
    virtual void Step();
    virtual void TakeDamage(uint32_t,uint32_t);
};
