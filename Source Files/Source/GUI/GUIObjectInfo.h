#pragma once

#include "GUIObjects/GUIObjectInfoElement.h"


class GUIObjectInfo:public Object
{
    uint32_t * PlayerFraction;
    std::vector <GUIObjectInfoElement*> Elements;
    void QuickDelete(std::list <ObjectInfo*>::iterator&);
    void ClearElements();
public:
    GUIObjectInfo();
    virtual ~GUIObjectInfo();
    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void Refresh();
    void SetPlayerFraction(uint32_t*);

};
