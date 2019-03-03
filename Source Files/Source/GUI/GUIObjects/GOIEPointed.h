#pragma once
#include "GOIENumber.h"
#include "../../Pointers/uint32_t_pointer.h"


class GOIEPointed:public GOIENumber
{
    uint32_t_pointer * pointer;
public:
    GOIEPointed(Position,Position,sf::Color,uint32_t_pointer*);
    GOIEPointed(Position,GOIENumber,uint32_t_pointer*);
    GOIEPointed(GOIEPointed&);
    virtual ~GOIEPointed();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void SetToDestroy();
};
