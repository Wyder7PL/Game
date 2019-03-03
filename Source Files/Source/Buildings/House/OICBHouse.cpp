#include "OICBHouse.h"

OICBHouse::OICBHouse(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}

GUIObjectInfoElement * OICBHouse::Create(Position pos)
{
    return new GOIECBHouse(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}
