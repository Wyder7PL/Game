#include "OIPointedu32.h"


OIPointedu32::OIPointedu32(uint32_t_pointer * pointer,OINumber number)
:poi(pointer),num(number)
{

}

GUIObjectInfoElement * OIPointedu32::Create(Position pos)
{
    GOIEPointed * obj = new GOIEPointed(pos,*dynamic_cast<GOIENumber*>(num.Create(pos)),poi);
    obj->SetNumber(*poi->GetPointer());
    return obj;
}
