#pragma once


#include "EffectObject.h"
#include "Object.hpp"

#include <list>


class ObjectInserter
{
    friend class mainControler;
    std::list <Object*> Objects;
    std::list <EffectObject*> Effects;
public:
    void AddObject(Object*);
    void AddEffect(EffectObject*);
};

