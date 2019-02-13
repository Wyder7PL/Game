#include "OnBuildingDestroy.h"

OnBuildingDestroy::OnBuildingDestroy(bool what)
:What(what),Prevent(false){}

OnBuildingDestroy::~OnBuildingDestroy()
{
    if(!Prevent)
    {
        AddObject add;
        if(What)
            add.Add(new RoundEnd(Position(0,0),true));
        else
            add.Add(new RoundEnd(Position(0,0),false));
    }

}
