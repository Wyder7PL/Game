#pragma once

#include "../../Markable/BlueprintButton.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "OICBWorkshop.h"
#include "../../Textures/Textures.h"

class WorkshopBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    WorkshopBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
