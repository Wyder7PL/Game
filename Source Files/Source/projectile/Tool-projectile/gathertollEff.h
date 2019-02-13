#pragma once
#include "../projectileEff.h"
#include "../../Materials/Natural-Resources/NaturalResource.h"

class gathertollEff:public projectileEff
{
    uint32_t id;
public:
    gathertollEff(uint32_t,uint32_t);
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
