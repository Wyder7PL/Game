#pragma once

#include "Sight.h"
#include "../Skills/Skill.h"

class Creature
{
    Sight * sight;
    bool blink;
    public:
        Creature(uint32_t);
        virtual ~Creature();

        uint32_t GetFraction();

        virtual bool Look(Position);
        void SetSeenRange(float);
        float GetSeenRange();
    protected:
        uint32_t Fraction;
        float SeenRange;
        std::list <Info> SeenObjects;
        Info* GetNearest(float&,Position);
        virtual bool TypeComparation(std::list <Info>::iterator)=0;
    private:
};
