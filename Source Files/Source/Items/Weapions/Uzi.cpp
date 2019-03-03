#include "Uzi.h"

Uzi::Uzi(uint32_t f)
:SingleShot(f)
{
    SetDamage(6);
    SetRange(180);
    SetAccuarity(70);
    SetShootRate(3);
    SetFullMagazine(30);
    SetMagazine(30);
    SetReloadTime(30*100);
    image.setTexture(Textures::textures->Uzi);
}

Uzi::~Uzi(){}
