#pragma once

#include "../../Anoyher/EffectObject.h"
#include "../../Markable/Markable.h"

class TreeCollision:public EffectObject
{
    Position position;
    float TrunkRadius;
public:
    TreeCollision(uint32_t,float);
    virtual ~TreeCollision();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
};

