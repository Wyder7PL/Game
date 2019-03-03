#include "HookGun.h"

HookGun::HookGun(uint32_t f)
:SingleShot(f)
{
    SetRange(300);
    SetAccuarity(100);
    SetShootRate(0);
    SetFullMagazine(1);
    SetMagazine(1);
    SetReloadTime(5*100);
    image.setTexture(Textures::textures->HookGun);
}

HookGun::~HookGun(){}

void HookGun::CreateBullet(Position pos,Position target)
{
    hook * p = new hook(pos,fractions);
    p->Push(Position(pos.angle(target),7.0));
    p->SetFractions(fractions);
    AddObject add;
    add.Add(p);
}
