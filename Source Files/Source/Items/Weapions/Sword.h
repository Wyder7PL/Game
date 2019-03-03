#pragma once
#include "CloseCombatItem.h"
#include "../../projectile/Weapion-projectile/sword.h"

class Sword:public CloseCombatItem
{
   public:
       Sword(uint32_t);
       virtual bool Attack(Position,Position);
};
