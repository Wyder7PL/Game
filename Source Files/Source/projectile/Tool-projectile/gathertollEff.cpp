#include "gathertollEff.h"

gathertollEff::gathertollEff(uint32_t a,uint32_t i):id(i)
{
    affected = a;
}
void gathertollEff::Step(ObjectInserter&,Object*){}
void gathertollEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{

    NaturalResource * nat = dynamic_cast<NaturalResource*>(obj);
    if(nat != NULL && nat->GetID() == id)
        nat->TakeResource();

}
void gathertollEff::OnDestroy(ObjectInserter & ins){}
