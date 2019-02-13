#pragma once

#include "../Building.h"
#include "../../Textures/Textures.h"

class House:public Building
{
public:
    House(Position,uint32_t);
    ~House();
    virtual void CreateInfo(std::list<Info>&);
};
