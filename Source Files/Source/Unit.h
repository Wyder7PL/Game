#pragma once

#include "Creature/Creature.h"
#include "Items/Armors/Armor.h"
#include "Items/ResourceItem.h"
#include "Markable/MarkUnit.h"
#include "Skills/NonCombatSkill.h"

class Unit:public MarkUnit,public Creature
{
public:
    Unit(Position,uint32_t,bool=true);
    virtual ~Unit();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetFraction();
    virtual bool GiveItem(Item*)=0;
    virtual void WearArmor(Armor*)=0;
    virtual void SetSkill(Skill*)=0;
    virtual ResourceItem * TakeItem(uint32_t,uint32_t)=0;
    virtual Item * GetActiveTool()=0;
    virtual Skill * GetActiveSkill()=0;
    void StartOccupying();
    virtual void EnterNeartestFortification();
    void ForceToIgnoreEnemy(bool);
private:
    bool HouseOccupy;
    bool FocusedOnFortification;
    uint32_t FocusedID;
    uint32_t FocusedSlot;
protected:
    void ResetMass(float);
    virtual bool TypeComparation(std::list <Info>::iterator);
    float DefaultMass;
    float ItemMass;
    bool EnemyIgnore;
};

class UnitTask:public EffectObject
{
public:
    UnitTask(uint32_t);
};

