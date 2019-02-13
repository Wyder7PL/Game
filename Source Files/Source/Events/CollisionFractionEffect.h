#pragma once

#include "../Anoyher/EffectObject.h"
#include "../Markable/Markable.h"
#include "EndOnNoFractionObjects.h"

class CollisionFractionEffect:public EffectObject
{
    uint32_t fraction;
    bool collided;
    bool AfterCollision;
public:
    CollisionFractionEffect(uint32_t,uint32_t);
    void OnCollision(ObjectInserter&,Object*);
    void Step(ObjectInserter&,Object*);
};
