#include "Sword.h"

Sword::Sword(uint32_t f)
:CloseCombatItem(f)
{
    SetRange(60);
    SetSpeed(10);
    image.setTexture(Textures::textures->Sword);
}


bool Sword::Attack(Position pos,Position target)
{
    if(GetCooldown() == 0 && pos.distance(target) < GetRange())
    {
        sword * p = new sword(pos.GMP(pos.angle(target),20),fractions,GetRange()/2,5);
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
