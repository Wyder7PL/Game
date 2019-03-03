#include "OICBStoneTower.h"

OICBStoneTower::OICBStoneTower(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBStoneTower::Create(Position pos)
{
    GOIECBStoneTower * g = new GOIECBStoneTower(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
