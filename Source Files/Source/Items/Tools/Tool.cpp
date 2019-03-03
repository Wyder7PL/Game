#include "Tool.h"

Tool::Tool(uint32_t f)
:Item(f),Type(0),Charge(0){SetItemType(2);}



float Tool::GetRange()
{
    return range;
}
void Tool::SetRange(float r)
{
    range = r;
}
uint32_t Tool::GetSpeed()
{
    return speed;
}
void Tool::SetSpeed(uint32_t s)
{
    speed = s;
}

void Tool::SetType(uint32_t t)
{
    Type = t;
}
uint32_t Tool::GetType()
{
    return Type;
}
float Tool::GetSeenRange()
{
    return 500;
}
