#pragma once

#include "../GUIObjectInfoElement.h"
#include "../../../Pointers/uint32_t_pointer.h"

class GUIDoubleUint:public GUIObjectInfoElement
{
protected:
    uint32_t_pointer * first;
    uint32_t_pointer * second;
public:
    GUIDoubleUint(uint32_t_pointer*,uint32_t_pointer*);
    virtual ~GUIDoubleUint();
    virtual void Istep();
    virtual void Idraw(sf::RenderTarget & target,sf::RenderStates states);
    virtual void Step()=0;
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const=0;
};
