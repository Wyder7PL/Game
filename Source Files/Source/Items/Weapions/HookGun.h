#pragma once
#include "SingleShot.h"
#include "../../projectile/Weapion-projectile/hook.h"

class HookGun:public SingleShot
{
public:
    HookGun(uint32_t);
    virtual ~HookGun();
protected:
    virtual void CreateBullet(Position,Position);
};
