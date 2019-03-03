#include "CloseCombatItem.h"

CloseCombatItem::CloseCombatItem(uint32_t f)
:Item(f)
{
    SetItemType(1);
    cooldown = 0;
}
CloseCombatItem::~CloseCombatItem()
{

}

float CloseCombatItem::GetRange()
{
    return range;
}
void CloseCombatItem::SetRange(float r)
{
    range = r;
}
float CloseCombatItem::GetSpeed()
{
    return speed;
}
void CloseCombatItem::SetSpeed(uint32_t s)
{
    speed = s;
}
uint32_t CloseCombatItem::GetCooldown()
{
    return cooldown;
}
void CloseCombatItem::SetCooldown(uint32_t c)
{
    cooldown = c;
}
float CloseCombatItem::GetSeenRange()
{
    return 210;
}
