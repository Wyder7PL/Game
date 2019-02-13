#include "ConstructionTool.h"

ConstructionTool::ConstructionTool(uint32_t f):Tool(f){}

uint32_t ConstructionTool::Build(Position pos,Position target)
{
    if(pos.distance(target) < GetRange())
    {
        if(Charge == Price)
        {
            constructiontool * t = new constructiontool(target,fractions,GetType());
            AddObject add;
            add.Add(t);
            Charge = 0;
            return 2;
        }
        Charge++;
        return 1;
    }
    return 0;
}
bool ConstructionTool::Refill(Position pos,Position target)
{
    if(pos.distance(target) < GetRange())
    {
        WorkPoints = MaxWorkPoints;
        return true;
    }
    return false;
}
void ConstructionTool::setMaxWorkPoints(uint32_t wp)
{
    MaxWorkPoints = wp;
}
uint32_t ConstructionTool::GetMaxWorkPoints()
{
    return MaxWorkPoints;
}
void ConstructionTool::SetWorkPoints(uint32_t wp)
{
    WorkPoints = wp;
}
uint32_t ConstructionTool::GetWorkPoints()
{
    return WorkPoints;
}
void ConstructionTool::SetType(uint32_t t)
{
    Tool::SetType(t);
    Price = (*ResourceStorage::ResourcesList)[t]->build->buildcost;
}
