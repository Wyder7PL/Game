#include "Object.hpp"


Object::Object(Position pos)
:PhysicObject(pos),ToDestroy(false),Desactivated(false),ID(GlobalID)
{
    GlobalID++;
}

Object::~Object()
{

}

void Object::Destroy()
{
    PhysicObject::toClear = true;
    GraphicObject::toClear = true;
    ToDestroy = true;
}

void Object::Desactivate()
{
    PhysicObject::toClear = true;
    GraphicObject::toClear = true;
    Desactivated = true;
}

bool Object::IsDestroyed()
{
    return ToDestroy;
}
bool Object::IsDesactivated()
{
    return Desactivated;
}
void Object::Activate()
{
    PhysicObject::toClear = false;
    GraphicObject::toClear = false;
    Desactivated = false;
}
uint32_t Object::GetID()
{
    return ID;
}

uint32_t Object::GlobalID = 1;


bool ObjectComparison(Object * a,Object * b)
{
    return(a->GetID() < b->GetID());
}
