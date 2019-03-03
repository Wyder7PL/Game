#pragma once

#include "../../Markable/BlueprintButton.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "OICBForester.h"
#include "../../Textures/Textures.h"

class ForesterBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    ForesterBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
