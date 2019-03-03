#include "bulletEff.h"

bulletEff::bulletEff(uint32_t a,uint32_t d)
:pos(0,0),pierce(1),damage(d)
{
    affected = a;
}

bulletEff::~bulletEff(){}

void bulletEff::Step(ObjectInserter&i,Object*obj)
{
    pos = obj->GetPosition();
    if(pierce == 0)
    {
        bullet * b = dynamic_cast<bullet*>(obj);
        if(b!=NULL)
            b->Existance = 0;
    }
}
void bulletEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    if(pierce>0)
    {
        Markable * bil = dynamic_cast<Markable*>(obj);
        if(bil != NULL &&(*Fraction::Fractions)[GetFractions()]->CompareFractions(bil->GetFraction())==0)
        {
            bil->DealDamage(damage,1);
            bil->Push(Position(pos.angle(obj->GetPosition()),1.0));
            pierce--;
        }
    }

}

void bulletEff::OnDestroy(ObjectInserter & ins)
{

}
