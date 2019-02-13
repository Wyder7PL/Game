#pragma once

#include "../GUIObjectInfoElement.h"
#include "../../../Markable/Clickable2.h"
#include "../../../Pointers/void_pointer.h"
#include "GOIEDropDown.h"

class OIDropDown:public ObjectInfo
{
    void_pointer * Elements;
    Position Dimension;
public:
    OIDropDown(Position,void_pointer*);
    virtual GUIObjectInfoElement * Create(Position);
};
