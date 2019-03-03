#include "Magazine.h"

Magazine::Magazine(Position pos,uint32_t f)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Tmagazine);
}

uint32_t Magazine::GiveResources(uint32_t t,uint32_t a)
{
    if(Fraction::Fractions == NULL || Fraction::Fractions->size() <= fraction)
        return a;
    (*Fraction::Fractions)[fraction]->GetEco()->GEE(t)->SetAmount((*Fraction::Fractions)[fraction]->GetEco()->GEE(t)->GetAmount()+a);
    return 0;
}

void Magazine::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 3;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}
