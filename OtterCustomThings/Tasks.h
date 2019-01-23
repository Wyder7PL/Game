#ifndef TASKS_H
#define TASKS_H

#include "../CustomBuildings/Tavern.h"

class Offense1Task:public UnitTask
{
    std::list <Position> CheckPoints;
    public:
        Offense1Task(uint32_t,std::list <Position>);
        virtual ~Offense1Task();
        virtual void Step(ObjectInserter&,Object*);
    protected:
    private:
};

class CreateUnitsOnAproach:public UnitTask
{
    bool Approached;
protected:
    std::list <BarrackUnitStorage> BUS;
    void SetApproached();
public:
    CreateUnitsOnAproach(uint32_t,std::list <BarrackUnitStorage>);
    virtual ~CreateUnitsOnAproach();
    virtual void OnCollision(ObjectInserter&,Object*)=0;
    virtual void Step(ObjectInserter&,Object*) final;

};
class CreateUnitsOnIDAproach:public CreateUnitsOnAproach
{
    uint32_t TargetID;
public:
    CreateUnitsOnIDAproach(uint32_t,std::list <BarrackUnitStorage>,uint32_t);
    virtual void OnCollision(ObjectInserter&,Object*);
};
class CreateUnitsOnFractionAproach:public CreateUnitsOnAproach
{
    uint32_t TargetFraction;
public:
    CreateUnitsOnFractionAproach(uint32_t,std::list <BarrackUnitStorage>,uint32_t);
    virtual void OnCollision(ObjectInserter&,Object*);
};

class CUOAScanObject:public Object
{
    sf::CircleShape temp;
public:
    CUOAScanObject(Position,float);
    virtual void SetToDestroy();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

#endif // TASKS_H
