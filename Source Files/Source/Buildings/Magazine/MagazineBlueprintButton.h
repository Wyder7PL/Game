#pragma once

#include "../../Markable/BlueprintButton.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "OICBMagazine.h"
#include "../../Textures/Textures.h"

class MagazineBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    MagazineBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
