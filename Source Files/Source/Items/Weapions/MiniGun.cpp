#include "MiniGun.h"

MiniGun::MiniGun(uint32_t f)
:SingleShot(f)
{
    SetRange(200);
    SetAccuarity(80);
    SetShootRate(0);
    SetFullMagazine(100);
    SetMagazine(45);
    SetReloadTime(50*100);
    image.setTexture(Textures::textures->Minigun);
}

MiniGun::~MiniGun(){}
