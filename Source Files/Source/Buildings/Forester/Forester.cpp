#include "Forester.h"

Forester::Forester(Position pos,uint32_t f)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Tforester);
    (*Fraction::Fractions)[f]->ChangeResidents(1);
}
Forester::~Forester(){(*Fraction::Fractions)[GetFraction()]->ChangeResidents(-1);}
void Forester::Step()
{
    Building::Step();
    if(rand()%2000==0)
    {
        Position pos(position.GetX()+(rand()%300)-150,position.GetY()+(rand()%300)-150);
        CommonTree * tree = new CommonTree(pos);
        AddObject add;
        add.Add(tree);
    }
}


void Forester::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 1;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}
