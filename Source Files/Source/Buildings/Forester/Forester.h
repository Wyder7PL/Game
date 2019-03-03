#pragma once

#include "../Building.h"
#include "../../Textures/Textures.h"
#include "../../Materials/Natural-Resources/CommonTree.h"

class Forester:public Building
{
public:
    Forester(Position,uint32_t);
    ~Forester();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
};
