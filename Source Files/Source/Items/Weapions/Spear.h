#pragma once
#include "CloseCombatItem.h"
#include "../../projectile/Weapion-projectile/spear.h"

class Spear:public CloseCombatItem
{
    public:
        Spear(uint32_t);
        virtual ~Spear();
        virtual bool Attack(Position,Position);
    protected:
    private:
};
