#pragma once

#include "../Unit.h"
#include "../Buildings/Tower/Barracks.h"
#include "CUOAScanObject.h"

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
