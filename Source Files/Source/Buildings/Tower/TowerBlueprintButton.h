#pragma once

#include "../../Markable/BlueprintButton.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "OICBTower.h"
#include "OICBStoneTower.h"
#include "../../Textures/Textures.h"

class TowerBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    TowerBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
