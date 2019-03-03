#pragma once

#include "../GUI/GUIObjects/GUIObjectInfoElement.h"
#include "../GUI/GUIObjects/GOIEText.h"
#include "../Markable/Clickable2.h"
#include "BuildingConstruction.h"
#include "../Creature/PreBuilding.h"



class GOIECreateButton:public Clickable2,public GUIObjectInfoElement
{
    GOIEText tex;
protected:
    uint32_t PlayerFraction;
public:
    GOIECreateButton(Position,Position,GOIEText,uint32_t);
    virtual ~GOIECreateButton();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void Selected();
};
