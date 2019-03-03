#pragma once

#include "../Unit.h"

class TestRace:public Unit
{
    Item * RightHand;
    Item * LeftHand;
    Armor * armor;
    HP * hp;
    Skill * ccs;
public:
    TestRace(Position,uint32_t,bool=true);
    virtual ~TestRace();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void DealDamage(uint32_t,uint32_t);
    virtual bool GiveItem(Item*);
    virtual ResourceItem * TakeItem(uint32_t,uint32_t);
    virtual Item * GetActiveTool();
    virtual Skill * GetActiveSkill();
    void SetRightItem(Item*);
    void SetLeftItem(Item*);
    virtual void WearArmor(Armor*);
    virtual void SetSkill(Skill*);
protected:
    virtual uint32_t GetSkillType();
private:
};
