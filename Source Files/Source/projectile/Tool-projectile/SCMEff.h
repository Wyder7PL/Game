#pragma once
#include "../projectileEff.h"

class SCMEff:public projectileEff
{
    uint32_t ID;
public:
    SCMEff(uint32_t,uint32_t);
    virtual ~SCMEff();
    void Step(ObjectInserter&,Object*);
    void OnCollision(ObjectInserter&,Object*);
    void OnDestroy(ObjectInserter&);
    void ChangeAffected(uint32_t);
    virtual void Communicate(Object*)=0;
};
