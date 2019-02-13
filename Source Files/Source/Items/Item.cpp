#include "Item.h"

Item::Item(uint32_t f)
:ItemType(0),fractions(f),Weight(0.3)
{

}

Item::~Item()
{
    //dtor
}

uint32_t Item::GetItemType()
{
    return ItemType;
}

float Item::GetWeight()
{
    return Weight;
}

void Item::SetItemType(uint32_t it)
{
    ItemType = it;
}

void Item::SetWeight(float it)
{
    Weight = it;
}

void Item::SetFractions(uint32_t f)
{
    fractions = f;
}

float Item::GetSeenRange()
{
    return 0;
}
sf::Sprite & Item::GetImage()
{
    return image;
}
