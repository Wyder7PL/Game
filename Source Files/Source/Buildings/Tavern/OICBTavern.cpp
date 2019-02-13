#include "OICBTavern.h"


OICBTavern::OICBTavern(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBTavern::Create(Position pos)
{
    GOIECBTavern * g = new GOIECBTavern(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
