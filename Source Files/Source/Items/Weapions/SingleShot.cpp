#include "SingleShot.h"

SingleShot::SingleShot(uint32_t f)
:Item(f),damage(1)
{
    SetItemType(1);
    SetActualReload(0);
    SetCooldown(0);
}
SingleShot::~SingleShot()
{

}

bool SingleShot::Shoot(Position pos,Position target)
{
    if(pow( pow(pos.GetX()-target.GetX(),2.0)+pow(pos.GetY()-target.GetY(),2.0) ,0.5) < GetRange())
    {
        if(magazine > 0 && cooldown == 0)
        {
            if(Charged())
            {
                CreateBullet(pos,target);
                magazine--;
                cooldown+=shootrate;
            }
            return true;
        }
        else if(magazine == 0 && actualreload == 0)
        {
            actualreload = reloadtime;
            return false;
        }
        if(cooldown>0)
        {
            cooldown--;
            return true;
        }
    }
    return false;
}

void SingleShot::Reload(uint32_t r)
{
    if(r >= actualreload)
    {
        actualreload = 0;
        magazine = fullmagazine;
    }
    else
        actualreload-=r;
}

void SingleShot::CreateBullet(Position pos,Position target)
{
    bullet * p = new bullet(pos,fractions,damage);
    p->Push(Position(pos.angle(target),15.0));
    p->SetFractions(fractions);
    AddObject add;
    add.Add(p);
}

float SingleShot::RandomBullet()
{
    float acc = (rand()%628)-314;
    acc/=(100*accuarity);
    return acc;
}

bool SingleShot::Charged()
{
    return true;
}

void SingleShot::SetDamage(uint32_t d)
{
   damage = d;
}
uint32_t SingleShot::GetDamage()
{
    return damage;
}

float SingleShot::GetRange()
{
    return range;
}
void SingleShot::SetRange(float r)
{
    range = r;
}

float SingleShot::GetAccuarity()
{
    return accuarity;
}
void SingleShot::SetAccuarity(float a)
{
    accuarity = a;
}
uint32_t SingleShot::GetCooldown()
{
    return cooldown;
}
void SingleShot::SetCooldown(uint32_t c)
{
    cooldown = c;
}
uint32_t SingleShot::GetShootRate()
{
    return shootrate;
}
void SingleShot::SetShootRate(uint32_t s)
{
    shootrate = s;
}
uint32_t SingleShot::GetFullMagazine()
{
    return fullmagazine;
}
void SingleShot::SetFullMagazine(uint32_t fm)
{
    fullmagazine = fm;
}
uint32_t SingleShot::GetMagazine()
{
    return magazine;
}
void SingleShot::SetMagazine(uint32_t m)
{
    magazine = m;
}
uint32_t SingleShot::GetReloadTime()
{
    return reloadtime;
}
void SingleShot::SetReloadTime(uint32_t rt)
{
    reloadtime = rt;
}
uint32_t SingleShot::GetActualReload()
{
    return actualreload;
}
void SingleShot::SetActualReload(uint32_t ar)
{
    actualreload = ar;
}
float SingleShot::GetSeenRange()
{
    return 250;
}
