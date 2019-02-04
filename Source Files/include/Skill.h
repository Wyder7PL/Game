#ifndef SKILL_H
#define SKILL_H

#include "Item.h"
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

class CloseCombat1:public Skill
{
public:
    CloseCombat1();
    virtual ~CloseCombat1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
    virtual uint32_t GetSkillType();
};

class CloseCombat2:public Skill
{
    public:
    CloseCombat2();
    virtual ~CloseCombat2();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
    virtual uint32_t GetSkillType();
};

class Shooting1:public Skill
{
public:
    Shooting1();
    virtual ~Shooting1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
    virtual uint32_t GetSkillType();
};

struct BuildOrder
{
    BuildOrder();
    bool ordered = false;
    Position pos;
    uint32_t TargetID;
    uint32_t Type;
    uint32_t Hits;
};

class Dereserve:public SCMEff
{
    uint32_t Rtype;
    uint32_t Amount;
public:
    Dereserve(uint32_t,uint32_t,uint32_t);
    virtual ~Dereserve();
    virtual void Communicate(Object*);
};

class NonCombatSkill:public Skill
{
protected:
    bool WorkCaneled;
    bool WorkAborted;
public:
    NonCombatSkill();
    void CanelWork(bool);
    void AbortWork(bool);
};

class Building1:public NonCombatSkill
{
    BuildOrder order;


    Info * magasine;
    uint32_t GoToMagasine(ConstructionTool*,Info*,Position);
public:
    Building1();
    virtual ~Building1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
};
class Gathering1:public NonCombatSkill
{
    bool FocusedOnResource;
    bool FocusedOnMagazine;
    uint32_t FocusedID;

public:
    Gathering1();
    virtual ~Gathering1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
};

class Mining1:public NonCombatSkill
{
    bool FocusedOnWorkPlace;
    bool FocusedOnMagazine;
    uint32_t FocusedID;
    uint32_t FocusedSlot;
public:
    Mining1();
    virtual ~Mining1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
};

class Working1:public NonCombatSkill
{
    bool FocusedOnWorkPlace;
    bool FocusedOnMagazine;
    uint32_t FocusedID;
    uint32_t FocusedSlot;
    uint32_t FocusedResourceID;
    uint32_t FocusedMagazineID;
public:
    Working1();
    virtual ~Working1();
    virtual uint32_t Step(Position,std::list<Item**>*,std::list<Info>*);
private:
    bool checktypedynamiccast(Item **,uint32_t);
};

#endif // SKILL_H
