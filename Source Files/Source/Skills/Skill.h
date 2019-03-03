#pragma once
#include "../Items/Item.h"
#include "../Markable/Slot.h"
#include <list>

class Skill
{
    public:
        Skill();
        virtual ~Skill();
        virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*)=0;
        Position Destination();
        Slot * GetSlot();
        float Speed();
        void ChangeFraction(uint32_t);
        virtual uint32_t GetSkillType();
        float GetChangedMass();
    protected:
        uint32_t fractions;
        Position destination;
        float speedModyhicator;
        Slot * SlotAddres;
        float ChangegMass;
    private:
};

/// ////////////////// ///
/// Step return:       ///
/// 0.nothing          ///
/// 1.move             ///
/// 2.enter            ///
/// 3.cooldown somehow ///
///                    ///
/// ////////////////// ///
