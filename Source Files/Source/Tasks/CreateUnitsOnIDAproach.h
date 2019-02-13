#pragma once

#include "CreateUnitsOnAproach.h"

class CreateUnitsOnIDAproach:public CreateUnitsOnAproach
{
    uint32_t TargetID;
public:
    CreateUnitsOnIDAproach(uint32_t,std::list <BarrackUnitStorage>,uint32_t);
    virtual void OnCollision(ObjectInserter&,Object*);
};
