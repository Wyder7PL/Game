#include "OISlotElementsStorage.h"

OISlotElementsStorage::OISlotElementsStorage(std::list<void_pointer*> poi,std::list<CTextureReferenceIllusion> tex)
:pointers(poi),textures(tex){}
GUIObjectInfoElement * OISlotElementsStorage::Create(Position pos)
{
    return new GOIESlotElementsStorage(pos,pointers,textures);
}
