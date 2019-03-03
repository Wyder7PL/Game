#include "SightEffect.h"

SightEffect::SightEffect(uint32_t id)
:Steps(0)
{
    affected = id;
}

SightEffect::~SightEffect(){}

void SightEffect::Step(ObjectInserter& Inserter,Object * obj)
{
    Steps++;
    if(Steps > 2)
    {
        Sight * sig = dynamic_cast<Sight*>(obj);
        if(sig!=NULL)
        {
            sig->Objects = Objects;
            sig->SetReady();
            Objects.clear();
        }

    }
}
void SightEffect::OnCollision(ObjectInserter& Inserter,Object * obj)
{
    if(Steps < 2)
    {
        Markable * m = dynamic_cast<Markable*>(obj);
        if(m != NULL)
            m->CreateInfo(Objects);
    }
}
void SightEffect::OnDestroy(ObjectInserter& Inserter)
{

}
