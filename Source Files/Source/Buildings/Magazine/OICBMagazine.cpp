#include "OICBMagazine.h"

OICBMagazine::OICBMagazine(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}

GUIObjectInfoElement * OICBMagazine::Create(Position pos)
{
    GOIECBMagazine * g = new GOIECBMagazine(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
