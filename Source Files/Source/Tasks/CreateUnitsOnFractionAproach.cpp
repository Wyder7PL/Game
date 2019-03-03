#include "CreateUnitsOnFractionAproach.h"

CreateUnitsOnFractionAproach::CreateUnitsOnFractionAproach(uint32_t id,std::list <BarrackUnitStorage> bus,uint32_t tfr)
:CreateUnitsOnAproach(id,bus),TargetFraction(tfr)
{

}
void CreateUnitsOnFractionAproach::OnCollision(ObjectInserter & Inserter,Object * obj)
{
    Unit * uuu = dynamic_cast<Unit*>(obj);
    if(uuu!=NULL && uuu->GetFraction()==TargetFraction)
        SetApproached();
}
