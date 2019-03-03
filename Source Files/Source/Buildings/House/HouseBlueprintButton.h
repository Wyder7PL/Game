#pragma once

#include "../../Markable/BlueprintButton.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "OICBHouse.h"
#include "../../Textures/Textures.h"


class HouseBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    HouseBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
