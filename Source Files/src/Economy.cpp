#include "../include/Economy.h"

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

Economy::Economy()
{
    ReSet();
}

Economy::~Economy()
{
    for(std::vector <EconomyElement*>::iterator ite = Elements.begin();ite!=Elements.end();ite++)
        delete (*ite);
    Elements.clear();
}

void Economy::ReSet()
{
    EconomyElement * eco;
    for(uint32_t i = 0;i < ResourceStorage::ResourcesList->size();i++)
    {
        eco = new EconomyElement();
        Elements.push_back(eco);
    }
}

EconomyElement* Economy::GEE(uint32_t e)
{
    if(e<Elements.size())
        return Elements[e];
    return NULL;
}
