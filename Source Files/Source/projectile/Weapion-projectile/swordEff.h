#pragma once
#include "../projectileEff.h"
#include "../../Markable/Markable.h"
#include "../../Fraction.h"

class swordEff:public projectileEff
{
    uint32_t damage;
public:
    swordEff(uint32_t,uint32_t);
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
