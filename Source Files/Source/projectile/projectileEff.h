#pragma once
#include "../Anoyher/EffectObject.h"

class projectileEff:public EffectObject
{
    uint32_t fractions;
public:
    projectileEff();
    virtual ~projectileEff();
    uint32_t GetFractions();
    void SetFractions(uint32_t);
};

