#pragma once

#include "../AddObject.h"
#include "RoundEnd.h"

class OnBuildingDestroy
{
protected:
    bool What;
    bool Prevent;
public:
    OnBuildingDestroy(bool);
    virtual ~OnBuildingDestroy();
};
