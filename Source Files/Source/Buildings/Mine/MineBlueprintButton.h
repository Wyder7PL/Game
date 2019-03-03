#pragma once

#include "../../Markable/BlueprintButton.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "OICBMine.h"
#include "../../Textures/Textures.h"

class MineBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    MineBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
