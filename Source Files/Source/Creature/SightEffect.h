#pragma once

#include <stdint.h>
#include "../Anoyher/EffectObject.h"
#include "../Markable/Markable.h"
#include "Sight.h"

class SightEffect:public EffectObject
{
    std::list <Info> Objects;
    uint32_t Steps;
public:
    SightEffect(uint32_t);
    virtual ~SightEffect();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
