#include "Armor.h"

Armor::Armor(uint32_t f):Item(f){SetItemType(4);}
uint32_t Armor::GTZ(uint32_t amount,uint32_t decrease)
{
    if(amount > decrease)
        return amount-decrease;
    return 0;
}
uint32_t Armor::GTO(uint32_t amount,uint32_t decrease)
{
    if(amount > decrease)
        return amount-decrease;
    return 1;
}
