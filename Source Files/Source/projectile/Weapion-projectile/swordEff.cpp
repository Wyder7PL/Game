#include "swordEff.h"

swordEff::swordEff(uint32_t a,uint32_t d)
:damage(d)
{
    affected = a;
}

void swordEff::Step(ObjectInserter&,Object*){}
void swordEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    Markable * mar = dynamic_cast<Markable*>(obj);
    if(mar != NULL && (*Fraction::Fractions)[GetFractions()]->CompareFractions(mar->GetFraction())==0)
        mar->DealDamage(damage,2);
}

void swordEff::OnDestroy(ObjectInserter & ins)
{

}
