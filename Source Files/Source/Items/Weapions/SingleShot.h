#pragma once
#include "../Item.h"
#include "../../projectile/Weapion-projectile/bullet.h"

class SingleShot:public Item
{
    uint32_t damage;
    float range;
    float accuarity;//1-3.14//
    uint32_t cooldown;
    uint32_t shootrate;
    uint32_t fullmagazine;
    uint32_t magazine;
    float reloadtime;
    float actualreload;
    public:
        SingleShot(uint32_t);
        virtual ~SingleShot();
        virtual bool Shoot(Position,Position);
        virtual void Reload(uint32_t);
        uint32_t GetActualReload();
        virtual float GetSeenRange();

        float GetRange();
    protected:
        virtual void CreateBullet(Position,Position);
        virtual float RandomBullet();
        virtual bool Charged();

        void SetDamage(uint32_t);
        uint32_t GetDamage();


        void SetRange(float);
        float GetAccuarity();
        void SetAccuarity(float);
        uint32_t GetCooldown();
        void SetCooldown(uint32_t);
        uint32_t GetShootRate();
        void SetShootRate(uint32_t);
        uint32_t GetFullMagazine();
        void SetFullMagazine(uint32_t);
        uint32_t GetMagazine();
        void SetMagazine(uint32_t);
        uint32_t GetReloadTime();
        void SetReloadTime(uint32_t);

        void SetActualReload(uint32_t);
    private:
};
