#pragma once
#include "../projectile/Tool-projectile/SCMEff.h"
#include "../Buildings/Construction.h"

class Dereserve:public SCMEff
{
    uint32_t Rtype;
    uint32_t Amount;
public:
    Dereserve(uint32_t,uint32_t,uint32_t);
    virtual ~Dereserve();
    virtual void Communicate(Object*);
};
