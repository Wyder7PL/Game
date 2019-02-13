#pragma once
#include "StorageComponent.h"

class ToolBox:public StorageComponent
{
public:
    ToolBox(uint32_t);
    ResourceItem * GetExtractedItem();
};
