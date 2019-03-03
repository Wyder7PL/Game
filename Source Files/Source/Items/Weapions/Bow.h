#pragma once
#include "SingleShot.h"
#include "../../projectile/Weapion-projectile/bullet.h"

class Bow:public SingleShot
{
    uint32_t charge;
    uint32_t chargetime;
public:
    Bow(uint32_t);
    virtual ~Bow();


    virtual float GetSeenRange();

    virtual bool Charged();
    virtual void CreateBullet(Position,Position);

    void SetChargeTime(uint32_t);
};
