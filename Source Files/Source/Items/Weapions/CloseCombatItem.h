#pragma once

#include "../Item.h"

class CloseCombatItem: public Item
{
    float range;
    uint32_t speed;
    uint32_t cooldown;
    public:
        CloseCombatItem(uint32_t);
        virtual ~CloseCombatItem();
        virtual bool Attack(Position,Position)=0;
        virtual float GetSeenRange();
    protected:
        float GetRange();
        void SetRange(float);
        float GetSpeed();
        void SetSpeed(uint32_t);
        uint32_t GetCooldown();
        void SetCooldown(uint32_t);
    private:
};
