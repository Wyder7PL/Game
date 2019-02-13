#include "spearEff.h"

spearEff::spearEff(uint32_t a)
{
    affected = a;
}

spearEff::~spearEff(){}

void spearEff::Step(ObjectInserter&,Object*){}
void spearEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    Markable * mar = dynamic_cast<Markable*>(obj);
    if(mar != NULL && (*Fraction::Fractions)[GetFractions()]->CompareFractions(mar->GetFraction())==0)
        mar->DealDamage(5,1);
}

void spearEff::OnDestroy(ObjectInserter & ins)
{

}
