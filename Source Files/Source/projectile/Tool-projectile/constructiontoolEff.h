#pragma once

#include "../projectileEff.h"
#include "../../Buildings/Construction.h"

class constructiontoolEff:public projectileEff
{
    uint32_t Rtype;
public:
    constructiontoolEff(uint32_t,uint32_t);
    virtual ~constructiontoolEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
