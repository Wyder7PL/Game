#include "OICBForester.h"

OICBForester::OICBForester(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}

GUIObjectInfoElement * OICBForester::Create(Position pos)
{
    return new GOIECBForester(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
}





