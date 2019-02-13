#pragma once

#include "GUIResource.h"
#include "GUIBlueprintButton.h"
#include "GUIObjectInfo.h"


class GUI:public Object
{
    GUIResource Resources;
    GUIBlueprintButton BlueprintButtons;
    GUIObjectInfo ObjectsInfo;
    uint32_t PlayerFraction;
    sf::RectangleShape background;
    sf::RectangleShape lines[2];
    public:
        GUI();
        virtual ~GUI();
        void DestroyElements();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        void Refresh();
        void SetPlayerFraction(uint32_t);

    protected:
    private:
        void ConnectFractionToObjects();
};
