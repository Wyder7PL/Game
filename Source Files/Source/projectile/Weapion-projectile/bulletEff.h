#pragma once
#include "../projectileEff.h"
#include "bullet.h"

class bulletEff:public projectileEff
{
    Position pos;
    uint32_t pierce;
    uint32_t damage;
public:
    bulletEff(uint32_t,uint32_t);
    virtual ~bulletEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
