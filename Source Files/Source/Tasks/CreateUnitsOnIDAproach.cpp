#include "CreateUnitsOnIDAproach.h"

CreateUnitsOnIDAproach::CreateUnitsOnIDAproach(uint32_t id,std::list <BarrackUnitStorage> bus,uint32_t tid)
:CreateUnitsOnAproach(id,bus),TargetID(tid)
{

}
void CreateUnitsOnIDAproach::OnCollision(ObjectInserter & Inserter,Object * obj)
{
    if(obj->GetID()==TargetID)
        SetApproached();
}
