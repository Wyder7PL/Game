#pragma once

#include "../projectileEff.h"
#include "hook.h"


class hookEff:public projectileEff
{
    Position pos;
    uint32_t pierce;
    uint32_t step;
public:
    hookEff(uint32_t);
    virtual ~hookEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
