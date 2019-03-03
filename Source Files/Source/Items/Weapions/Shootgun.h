#pragma once
#include "SingleShot.h"
#include "../../projectile/Weapion-projectile/bullet.h"

class Shootgun:public SingleShot
{
public:
    Shootgun(uint32_t);
protected:
    virtual void CreateBullet(Position,Position);
};
