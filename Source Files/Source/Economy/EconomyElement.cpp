#include "EconomyElement.h"

EconomyElement::EconomyElement(/*uint32_t t*/)
://type(t),
amount(0),reserved(0),locked(false)
{

}
EconomyElement::~EconomyElement(){}

void EconomyElement::SetAmount(int32_t a)
{
    amount = a;
}
void EconomyElement::ChangeAmount(int32_t a)
{
    amount += a;
}
void EconomyElement::UnReserve(int32_t a)
{
    amount -= a;
    reserved -= a;
}
void EconomyElement::Reserve(uint32_t r)
{
    reserved += r;
}
int32_t EconomyElement::GetAmount()
{
    return amount;
}
int32_t EconomyElement::GetNonReservedAmount()
{
    return amount-reserved;
}
void EconomyElement::Lock(bool l)
{
    locked = l;
}
