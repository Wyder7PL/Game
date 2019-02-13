#include "OICBTower.h"

OICBTower::OICBTower(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBTower::Create(Position pos)
{
    GOIECBTower * g = new GOIECBTower(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
