#pragma once
#include "StorageComponent.h"
#include "../../projectile/Tool-projectile/gathertoll.h"

class GatherTool:public StorageComponent
{
public:
    GatherTool(uint32_t);
    virtual uint32_t Gather(Position,Position,uint32_t);
};
