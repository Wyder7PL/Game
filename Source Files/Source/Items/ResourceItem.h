#pragma once
#include "Item.h"


class ResourceItem:public Item
{
    uint32_t type;
    uint32_t amount;
    uint32_t maxamount;
public:
    ResourceItem(uint32_t,uint32_t);
    uint32_t GetType();
};
