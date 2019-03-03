#pragma once
#include "../Item.h"

class Armor:public Item
{
public:
    Armor(uint32_t);
    virtual uint32_t DecreaseDamage(uint32_t,uint32_t)=0;
protected:
    uint32_t GTZ(uint32_t,uint32_t);///Ground to zero
    uint32_t GTO(uint32_t,uint32_t);///Ground to one
};
