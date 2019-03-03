#pragma once

#include "Construction.h"


class Collision:public EffectObject
{
    Position position;
public:
    Collision( uint32_t);
    virtual ~Collision();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
};

