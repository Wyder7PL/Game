#pragma once

#include "../Textures/Textures.h"
#include "../Fraction.h"
#include "ResourceInfo.h"

class GUIResource:public Object
{
    ResourceInfo wood;
    ResourceInfo stone;
    ResourceInfo iron;
    ResourceInfo gold;
    ResourceInfo residens;
    ResourceInfo maxresidens;
    uint32_t * PlayerFraction;
public:
    GUIResource();
    virtual ~GUIResource();
    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void SetPlayerFraction(uint32_t*);
};

