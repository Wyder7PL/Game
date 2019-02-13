#pragma once

#include "../Building.h"
#include "../../Textures/Textures.h"

class Magazine:public Building
{
public:
    Magazine(Position,uint32_t);
    uint32_t GiveResources(uint32_t,uint32_t);
    virtual void CreateInfo(std::list<Info>&);
};
