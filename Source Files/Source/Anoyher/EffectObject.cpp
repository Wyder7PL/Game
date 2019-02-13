#include "EffectObject.h"


EffectObject::EffectObject()
{
    toClear = false;
}

EffectObject::~EffectObject()
{
    //dtor
}

void EffectObject::OnCollision(ObjectInserter & obi,Object * obj){}

void EffectObject::OnDestroy(ObjectInserter & obi){}

uint32_t EffectObject::CreatorID()
{
    return creator;
}

uint32_t EffectObject::AffectedID()
{
    return affected;
}

void EffectObject::SetToClear()
{
    toClear = true;
}

bool EffectObject::IsToClear()
{
    return toClear;
}



bool EffectComparison(EffectObject * a,EffectObject * b)
{
    return(a->AffectedID() < b->AffectedID());
}

