#pragma once
#include "Armor.h"

class IronPlateArmor:public Armor
{
public:
    IronPlateArmor(uint32_t);
    virtual uint32_t DecreaseDamage(uint32_t,uint32_t);
};
