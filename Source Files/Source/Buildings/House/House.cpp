#include "House.h"

House::House(Position pos,uint32_t f)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Thouse);
    (*Fraction::Fractions)[f]->ChangeMaxResidents(1);
}
House::~House(){(*Fraction::Fractions)[GetFraction()]->ChangeMaxResidents(-1);}

void House::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 4;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}
