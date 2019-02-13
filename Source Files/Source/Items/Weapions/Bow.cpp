#include "Bow.h"

Bow::Bow(uint32_t f)
:SingleShot(f),charge(0)
{
    SetRange(170);
    SetAccuarity(100);
    SetShootRate(0);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(5*100);
    SetChargeTime(10);
    image.setTexture(Textures::textures->Bow);
}

Bow::~Bow(){}

float Bow::GetSeenRange()
{
    return 200;
}

bool Bow::Charged()
{
    if(charge < chargetime)
    {
        charge++;
        return false;
    }
    charge = 0;
    return true;
}
void Bow::CreateBullet(Position pos,Position target)
{
    bullet * p = new bullet(pos,fractions,5);
    p->Push(Position(pos.angle(target),15.0));
    p->SetFractions(fractions);
    AddObject add;
    add.Add(p);
}

void Bow::SetChargeTime(uint32_t cht)
{
    chargetime = cht;
}
