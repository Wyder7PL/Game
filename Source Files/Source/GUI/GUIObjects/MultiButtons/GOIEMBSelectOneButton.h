#pragma once

#include "../GUIObjectInfoElement.h"
#include "../../../Markable/Clickable2.h"

class GOIEMBSelectOneButton:public GUIObjectInfoElement,public Clickable2
{
    bool selected;
    sf::RectangleShape shape;
    sf::Sprite sprite;
    bool disabled;
public:
    GOIEMBSelectOneButton(Position,Position);
    GOIEMBSelectOneButton(Position,Position,const sf::Texture&);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void ChangePosition(Position);
    virtual void Selected();
    bool IsSelected();
    void Deselect();
    void Disable(bool);
};
