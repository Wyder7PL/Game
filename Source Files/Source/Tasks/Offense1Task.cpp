#include "Offense1Task.h"

Offense1Task::Offense1Task(uint32_t id,std::list <Position> chk)
:UnitTask(id),CheckPoints(chk)
{

}
Offense1Task::~Offense1Task(){}
void Offense1Task::Step(ObjectInserter & Inserter,Object * obj)
{
    if(CheckPoints.size()==0)
    {
        SetToClear();
        return;
    }
    Unit * uni = dynamic_cast<Unit*>(obj);
    if(uni != NULL)
    {
        Position pos = uni->GetPosition();
        if(pos.distance((*CheckPoints.begin()))<30)
        {
            CheckPoints.erase(CheckPoints.begin());
            return;
        }
        else
        {
            uni->ForceDestination((*CheckPoints.begin()));
            uni->ForceToIgnoreEnemy(false);
        }
    }
}
