#include "SCMEff.h"

SCMEff::SCMEff(uint32_t a,uint32_t id)
:ID(id)
{
    affected = a;
}
SCMEff::~SCMEff(){}
void SCMEff::Step(ObjectInserter&,Object*){}
void SCMEff::OnCollision(ObjectInserter& Inserter,Object* obj)
{
    if(obj->GetID()==ID)
        Communicate(obj);

}
void SCMEff::OnDestroy(ObjectInserter & ins){}
void SCMEff::ChangeAffected(uint32_t a){affected = a;}
