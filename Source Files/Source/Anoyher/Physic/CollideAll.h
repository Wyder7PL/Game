#pragma once

#include "PhysicShape.h"



class CollideAll:public PhysicShape
{
public:
    CollideAll();
    ~CollideAll();

    virtual bool CollideV2(PhysicShape*,Position,Position);
    virtual bool InArea(Position,Position);

    Position GetSize();
private:

};

