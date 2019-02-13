#include "WoodenArmor.h"

WoodenArmor::WoodenArmor(uint32_t f):Armor(f)
{
    image.setTexture(Textures::textures->WoodenArmor);
    image.setOrigin(50,50);
}

uint32_t WoodenArmor::DecreaseDamage(uint32_t damage,uint32_t type)
{
    return GTO(damage,2);
}
