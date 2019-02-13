#include "GraphicObject.h"


GraphicObject::GraphicObject()
{
    Zindex = 0;
    toClear = false;
}

GraphicObject::~GraphicObject()
{

}



int32_t GraphicObject::GetZIndex()
{
    return Zindex;
}
void GraphicObject::SetZIndex(int32_t i)
{
    Zindex = i;
}

bool GraphicObject::ToClear()
{
    return toClear;
}
