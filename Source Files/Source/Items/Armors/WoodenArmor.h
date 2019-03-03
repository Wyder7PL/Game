#pragma once
#include "Armor.h"

class WoodenArmor:public Armor
{
public:
    WoodenArmor(uint32_t);
    virtual uint32_t DecreaseDamage(uint32_t,uint32_t);
};
