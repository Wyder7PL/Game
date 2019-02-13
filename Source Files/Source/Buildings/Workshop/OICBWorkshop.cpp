#include "OICBWorkshop.h"

OICBWorkshop::OICBWorkshop(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}

GUIObjectInfoElement * OICBWorkshop::Create(Position pos)
{
    return new GOIECBWorkshop(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}
