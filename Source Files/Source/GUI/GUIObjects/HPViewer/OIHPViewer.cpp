#include "OIHPViewer.h"

OIHPViewer::OIHPViewer(uint32_t_pointer * pointer1,uint32_t_pointer * pointer2)
:OIDoubleUint(pointer1,pointer2)
{

}
GUIObjectInfoElement * OIHPViewer::Create(Position pos)
{
    return new GUIHPViewer(pos,GetFirst(),GetSecond());
}
