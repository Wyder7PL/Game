#pragma once

#include "../Buildings/Magazine/MagazineBlueprintButton.h"
#include "../Buildings/Tavern/TavernBlueprintButton.h"
#include "../Buildings/House/HouseBlueprintButton.h"
#include "../Buildings/Mine/MineBlueprintButton.h"
#include "../Buildings/Tower/TowerBlueprintButton.h"
#include "../Buildings/Workshop/WorkshopBlueprintButton.h"
#include "../Buildings/Forester/ForesterBlueprintButton.h"
#include "../Markable/BlueprintButton.h"


class GUIBlueprintButton:public Object
{
    uint32_t * PlayerFraction;
    std::vector <BlueprintButton*> Buttons;
public:
    GUIBlueprintButton();
    virtual ~GUIBlueprintButton();
    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void SetPlayerFraction(uint32_t*);
    void SetButtons();
};
