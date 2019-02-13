#include "BuildingSurvive.h"

BuildingSurvive::BuildingSurvive(bool what,uint32_t SurvivalTime)
:OnBuildingDestroy(what),win(false),Time(SurvivalTime)
{

}
BuildingSurvive::~BuildingSurvive()
{
    if(Time==0)
        Prevent = true;
}
void BuildingSurvive::Step()
{
    if(win)
        return;
    if(Time==0)
    {
        AddObject add;
        add.Add(new RoundEnd(Position(0,0),true));
        win=true;
    }
    else
        Time--;
}
