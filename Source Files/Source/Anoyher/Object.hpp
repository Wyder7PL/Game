#pragma once


#include "Graphic/GraphicControler.hpp"
#include "Physic/PhysicControler.hpp"




class Object:public GraphicObject,public PhysicObject
{
    static uint32_t GlobalID;
    bool ToDestroy;
    bool Desactivated;
    uint32_t ID;
protected:
    void Destroy();
    virtual void Desactivate();
public:
    Object(Position);
    virtual ~Object();
    virtual void Step() = 0;
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const = 0;
    bool IsDestroyed();
    bool IsDesactivated();
    virtual void Activate();
    uint32_t GetID();
};

bool ObjectComparison(Object*,Object*);
