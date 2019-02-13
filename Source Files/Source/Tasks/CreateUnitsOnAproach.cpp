#include "CreateUnitsOnAproach.h"

CreateUnitsOnAproach::CreateUnitsOnAproach(uint32_t id,std::list <BarrackUnitStorage> bus)
:UnitTask(id),Approached(false),BUS(bus){}

CreateUnitsOnAproach::~CreateUnitsOnAproach()
{
    for(std::list <BarrackUnitStorage>::iterator ite = BUS.begin();ite != BUS.end();ite++)
    {
        for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
            delete (*ite2);
        delete (*ite).warrior;
    }
}
void CreateUnitsOnAproach::SetApproached()
{
    Approached = true;
}

void CreateUnitsOnAproach::Step(ObjectInserter & Inserter,Object * obj)
{
    if(BUS.size()==0)
    {
        SetToClear();
        CUOAScanObject * scn = dynamic_cast<CUOAScanObject*>(obj);
        if(scn!=NULL)
            scn->SetToDestroy();
    }
    if(Approached)
    {
        for(std::list <BarrackUnitStorage>::iterator ite = BUS.begin();ite != BUS.end();)
        {
            if((*ite).RelaseTime==0)
            {
                Inserter.AddObject((*ite).warrior);
                for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
                    Inserter.AddEffect((*ite2));
                ite = BUS.erase(ite);
            }
            else
            {
                (*ite).RelaseTime--;
                ite++;
            }
        }
    }
}
