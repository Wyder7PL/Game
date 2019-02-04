#include "../include/Fraction.h"

std::vector <Fraction*> * Fraction::Fractions = NULL;

Fraction::Fraction(uint32_t f)
:FriendlyFractions(0),MaxResidents(4),Residents(0),FractionColor(sf::Color::Black)
{
    SetFractionFriendly(f);
}

Fraction::~Fraction()
{
    //dtor
}

Economy * Fraction::GetEco()
{
    return &eco;
}

uint32_t Fraction::GetMaxResidents()
{
    return MaxResidents;
}
uint32_t Fraction::GetResidents()
{
    return Residents;
}
void Fraction::ChangeMaxResidents(int32_t amount)
{
    int32_t r = MaxResidents;
    if(amount*(-1)>r)
        MaxResidents = 0;
    else
        MaxResidents += amount;
}
void Fraction::ChangeResidents(int32_t amount)
{
    int32_t r = Residents;
    if(amount*(-1)>r)
        Residents = 0;
    else
        Residents += amount;
}

uint32_t Fraction::GetFriendlyFractions()
{
    return FriendlyFractions;
}
void Fraction::SetFractionFriendly(uint32_t f)
{
    if(f==0)
        return;
    if(!(FriendlyFractions& 1 << (f-1) ))
        FriendlyFractions += (1 << (f-1));
}
void Fraction::SetFractionUnfriendly(uint32_t f)
{
    if(f==0)
        return;
    if(FriendlyFractions&1 << (f-1))
    FriendlyFractions -= (1 << (f-1));
}

uint32_t Fraction::CompareFractions(uint32_t f)
{
    if(f==0)
        return 0;
    return 1<<(f-1)&GetFriendlyFractions();
}

void Fraction::SetFractionColor(sf::Color c)
{
    FractionColor = c;
}
sf::Color Fraction::GetFractionColor()
{
    return FractionColor;
}
