#pragma once

#include "Markable.h"
#include "MultiUnitSelection.h"
#include "../AddObject.h"
#include "../Functions.h"

class MarkUnit:public Markable
{
    bool pervious;
    sf::CircleShape mark;

    bool ntm;///need to move?
    uint32_t ntmdenycooldown;
    Position Destination;
protected:
    static MultiUnitSelection * MUS;
    virtual void Desactivate();
    bool ForcedMove();
    Position ForcedDestination();
    virtual uint32_t GetSkillType()=0;
    virtual void QuickDeselect();
public:
    MarkUnit(Position);
    virtual ~MarkUnit();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    static void CreateMUS(MultiUnitSelection*);
    void MarkSize(float);
    virtual void CreateInfo(std::list<Info>&);
    void ForceDestination(Position);
};

/// /////////////////////////// ///
/// Skill type 1 << n-1         ///
/// 0 - None                    ///
/// 1 - Combat Only             ///
/// 2 - Close Combat            ///
/// 3 - Distance Combat         ///
/// /////////////////////////// ///

