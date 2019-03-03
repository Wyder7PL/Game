#pragma once

#include "../Building.h"
#include "../../Unit.h"
#include "../../Textures/Textures.h"

struct BarrackUnitStorage
{
    BarrackUnitStorage(Unit*,std::list<UnitTask*>,uint32_t);
    uint32_t RelaseTime;
    Unit * warrior;
    std::list <UnitTask*> Tasks;
};


class Barracks:public Building
{
    std::list <BarrackUnitStorage> StoredUnits;
public:
    Barracks(Position,uint32_t,std::list <BarrackUnitStorage>);
    virtual ~Barracks();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
};






