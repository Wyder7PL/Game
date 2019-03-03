#pragma once

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include "../Position.h"

#include <stdint.h>
#include <cstddef>
#include <random>

#define PI 3.14159265


class PhysicShape
{
protected:
    int32_t shape;
public:
    virtual ~PhysicShape();
    virtual bool CollideV2(PhysicShape*,Position,Position)=0;
    virtual bool InArea(Position,Position)=0;
    virtual Position GetSize()=0;
    virtual int32_t GetShape();
    virtual Position GetClosestEdge(Position,Position,float);
};

