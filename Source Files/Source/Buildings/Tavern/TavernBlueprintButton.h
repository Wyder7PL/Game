#pragma once

#include "../../Markable/BlueprintButton.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "OICBTavern.h"
#include "../../Textures/Textures.h"

class TavernBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    TavernBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
