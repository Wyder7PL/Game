#pragma once

#include "../GUI/GUIObjects/OIPT.h"
#include "../Textures/Textures.h"
#include "../Markable/BlueprintButton.h"




class BuildingBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    BuildingBlueprintButton(Position,uint32_t*);
    virtual ~BuildingBlueprintButton();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};

