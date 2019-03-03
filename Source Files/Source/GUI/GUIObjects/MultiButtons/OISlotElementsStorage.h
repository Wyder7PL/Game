#pragma once

#include "GOIEDropDown.h"
#include "../ObjectInfo.h"
#include "../CTextureReferenceIllusion.h"
#include "GOIESlotElementsStorage.h"

class OISlotElementsStorage:public ObjectInfo
{
    std::list<void_pointer*> pointers;
    std::list<CTextureReferenceIllusion> textures;
public:
    OISlotElementsStorage(std::list<void_pointer*>,std::list<CTextureReferenceIllusion>);
    virtual GUIObjectInfoElement * Create(Position);
};
