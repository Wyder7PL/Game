#include "OICBMine.h"

OICBMine::OICBMine(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBMine::Create(Position pos)
{
    return new GOIECBMine(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}
