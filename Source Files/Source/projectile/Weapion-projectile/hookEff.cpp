#include "hookEff.h"

hookEff::hookEff(uint32_t a)
:pos(0,0),pierce(1),step(0)
{
    affected = a;
}

hookEff::~hookEff(){}

void hookEff::Step(ObjectInserter&i,Object*obj)
{
    step++;
    pos = obj->GetPosition();
    if(pierce == 0)
    {
        hook * b = dynamic_cast<hook*>(obj);
        if(b!=NULL)
            b->Existance = 0;
    }

        chaineffect * eff = new chaineffect(obj->GetPosition());
        AddObject add;
        add.Add(eff);


}
void hookEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    if(pierce>0)
    {
        Markable * bil = dynamic_cast<Markable*>(obj);
        if(bil != NULL &&(*Fraction::Fractions)[GetFractions()]->CompareFractions(bil->GetFraction())==0)
        {
            bil->DealDamage(3,1);
            bil->Push(Position(obj->GetPosition().angle(pos),7.0*step));
            pierce--;
        }
    }

}

void hookEff::OnDestroy(ObjectInserter & ins)
{

}
