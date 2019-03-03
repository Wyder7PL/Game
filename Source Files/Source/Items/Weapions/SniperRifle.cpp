#include "SniperRifle.h"

SniperRifle::SniperRifle(uint32_t f)
:SingleShot(f)
{
    SetDamage(22);
    SetRange(280);
    SetAccuarity(130);
    SetShootRate(1);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(20*100);
    image.setTexture(Textures::textures->SniperRifle);
}
