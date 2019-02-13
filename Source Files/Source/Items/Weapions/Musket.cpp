#include "Musket.h"

Musket::Musket(uint32_t f)
:SingleShot(f)
{
    SetDamage(10);
    SetRange(210);
    SetAccuarity(100);
    SetShootRate(10);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(30*100);
    image.setTexture(Textures::textures->Musket);
}
