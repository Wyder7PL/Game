#include "Spear.h"

Spear::Spear(uint32_t f)
:CloseCombatItem(f)
{
    SetRange(80);
    SetSpeed(10);
    image.setTexture(Textures::textures->Spear);
}
Spear::~Spear()
{

}

bool Spear::Attack(Position pos,Position target)
{
    if(GetCooldown() == 0 && pos.distance(target) < GetRange())
    {
        spear * p = new spear(target,fractions);
        p->SetFractions(fractions);
        AddObject add;
        add.Add(p);
        SetCooldown(GetSpeed());
        return true;
    }
    else if(GetCooldown() > 0)
        SetCooldown(GetCooldown()-1);
    return false;
}
