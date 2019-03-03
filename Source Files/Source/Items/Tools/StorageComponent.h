#pragma once
#include "Tool.h"
#include "../ResourceItem.h"

class StorageComponent:public Tool
{
protected:
    ResourceItem * res;
public:
    StorageComponent(uint32_t);
    uint32_t Store(Position,Position,uint32_t,uint32_t);
    uint32_t Extract(Position,Position,uint32_t,uint32_t);
};
