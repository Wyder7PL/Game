#include "AddObject.h"

std::list <Object*> AddObject::objects;
std::list <EffectObject*> AddObject::effects;

AddObject::AddObject()
{

}

AddObject::~AddObject()
{

}

void AddObject::Add(Object * obj)
{
    AddObject::objects.push_back(obj);
}

void AddObject::Add(EffectObject * obj)
{
    AddObject::effects.push_back(obj);
}
