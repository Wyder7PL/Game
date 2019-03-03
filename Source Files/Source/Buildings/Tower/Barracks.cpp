#include "Barracks.h"

BarrackUnitStorage::BarrackUnitStorage(Unit * unit,std::list <UnitTask*> tasks,uint32_t RT)
:warrior(unit),Tasks(tasks),RelaseTime(RT){}

Barracks::Barracks(Position pos,uint32_t f,std::list <BarrackUnitStorage> bus)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Tbarracks);
    for(std::list <BarrackUnitStorage>::iterator ite = bus.begin();ite != bus.end();ite++)
        StoredUnits.push_back((*ite));

}
Barracks::~Barracks()
{
    for(std::list <BarrackUnitStorage>::iterator ite = StoredUnits.begin();ite != StoredUnits.end();ite++)
    {
        for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
            delete (*ite2);
        delete (*ite).warrior;
    }
}
void Barracks::Step()
{
    Building::Step();
    for(std::list <BarrackUnitStorage>::iterator ite = StoredUnits.begin();ite != StoredUnits.end();)
    {
        if((*ite).RelaseTime==0)
        {
            (*ite).warrior->SetPosition(position.GetX()+50,position.GetY());
            AddObject add;
            add.Add((*ite).warrior);
            for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
                add.Add((*ite2));
            ite = StoredUnits.erase(ite);
        }
        else
        {
            (*ite).RelaseTime--;
            ite++;
        }
    }
}
void Barracks::CreateInfo(std::list<Info>& Objects)
{
    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 1;
    inf.fraction = Building::GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}



