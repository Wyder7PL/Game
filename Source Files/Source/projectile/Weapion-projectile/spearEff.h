#pragma once
#include "../projectileEff.h"
#include "../../Markable/Markable.h"
#include "../../Fraction.h"

class spearEff:public projectileEff
{
public:
    spearEff(uint32_t);
    virtual ~spearEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
