#pragma once

#include "OnBuildingDestroy.h"
#include "RoundEnd.h"
#include "../AddObject.h"
//#include "../Anoyher/Position.h"
#include <stdint.h>

class BuildingSurvive:public OnBuildingDestroy
{
    bool win;
    uint32_t Time;
public:
    BuildingSurvive(bool,uint32_t);
    virtual ~BuildingSurvive();
    virtual void Step();
};
