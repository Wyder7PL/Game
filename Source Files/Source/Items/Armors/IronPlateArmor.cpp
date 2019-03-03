#include "IronPlateArmor.h"

IronPlateArmor::IronPlateArmor(uint32_t f):Armor(f)
{
    image.setTexture(Textures::textures->IronPlateArmor);
    image.setOrigin(50,50);
}

uint32_t IronPlateArmor::DecreaseDamage(uint32_t damage,uint32_t type)
{
    return GTO(damage,4);
}
