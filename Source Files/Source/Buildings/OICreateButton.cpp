#include "OICreateButton.h"

OICreateButton::OICreateButton(OIText t,uint32_t pfr)
:tex(t),PlayerFraction(pfr){}

OIText OICreateButton::GetTex()
{
    return tex;
}

OICreateButton::~OICreateButton(){}

GUIObjectInfoElement * OICreateButton::Create(Position pos)
{
    return new GOIECreateButton(pos,tex.GetWah(),*static_cast<GOIEText*>(tex.Create(pos)),GetPlayerFraction());
}

uint32_t OICreateButton::GetPlayerFraction()
{
    return PlayerFraction;
}













