#ifndef HP_H
#define HP_H

#include <stdint.h>

class HP
{
    int32_t hp;
    uint32_t full;
    public:
        HP(uint32_t,uint32_t=0);
        virtual ~HP();

        int32_t GetHP();
        int32_t GetMaxHP();

        virtual void Step();

        virtual void TakeDamage(uint32_t,uint32_t);
    protected:
    private:
};

/// ////////////////////// ///
/// Damage Type:           ///
/// 0 - clear              ///
/// 1 - piercing           ///
/// 2 - shlashing          ///
/// 3 - blunt              ///
/// 4 - fire               ///
/// 5 - water              ///
///                        ///
/// ////////////////////// ///

class WoodenHP:public HP
{
    uint32_t FireStrenght;
    uint32_t FireExistance;
public:
    WoodenHP(uint32_t,uint32_t=0);
    virtual ~WoodenHP();
    virtual void Step();
    virtual void TakeDamage(uint32_t,uint32_t);
};

#endif // HP_H
