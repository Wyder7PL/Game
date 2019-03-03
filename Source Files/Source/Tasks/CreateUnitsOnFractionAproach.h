#pragma once

#include "CreateUnitsOnAproach.h"

class CreateUnitsOnFractionAproach:public CreateUnitsOnAproach
{
    uint32_t TargetFraction;
public:
    CreateUnitsOnFractionAproach(uint32_t,std::list <BarrackUnitStorage>,uint32_t);
    virtual void OnCollision(ObjectInserter&,Object*);
};
