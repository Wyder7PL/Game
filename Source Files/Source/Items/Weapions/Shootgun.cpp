#include "Shootgun.h"

Shootgun::Shootgun(uint32_t f)
:SingleShot(f)
{
    SetDamage(8);
    SetRange(220);
    SetAccuarity(120);
    SetShootRate(10);
    SetFullMagazine(2);
    SetMagazine(2);
    SetReloadTime(20*100);
    image.setTexture(Textures::textures->DoubleShoot);
}

void Shootgun::CreateBullet(Position pos,Position target)
{
    AddObject add;
    bullet * b;
    for(uint32_t i = 0;i<5;i++)
    {
        float anglemod = (rand()%100-50),powermod = (rand()%100-50);
        anglemod/=200;
        powermod/=10;
        b = new bullet(pos,fractions,GetDamage());
        b->Push(Position(pos.angle(target)+anglemod,15.0+powermod));
        b->SetFractions(fractions);
        add.Add(b);
    }
}
