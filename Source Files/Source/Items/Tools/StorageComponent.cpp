#include "StorageComponent.h"

StorageComponent::StorageComponent(uint32_t f)
:Tool(f),res(NULL){}
uint32_t StorageComponent::Store(Position pos,Position target,uint32_t type,uint32_t amount)
{
    if(pos.distance(target) < GetRange())
    {
        (*Fraction::Fractions)[fractions]->GetEco()->GEE(type)->ChangeAmount(amount);
        return 1;
    }
    return 0;
}
uint32_t StorageComponent::Extract(Position pos,Position target,uint32_t type,uint32_t amount)
{
    if(pos.distance(target) < GetRange())
    {
        if((*Fraction::Fractions)[fractions]->GetEco()->GEE(type)->GetNonReservedAmount() >= amount)
        {
            res = new ResourceItem(fractions,type);
            (*Fraction::Fractions)[fractions]->GetEco()->GEE(type)->ChangeAmount(-amount);
            return 2;
        }
        return 1;
    }
    return 0;
}
