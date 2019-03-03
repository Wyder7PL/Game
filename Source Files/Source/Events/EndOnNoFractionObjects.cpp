#include "EndOnNoFractionObjects.h"



EndOnNoFractionObjects::EndOnNoFractionObjects(bool sw,uint32_t f)
:Object(Position(0,0)),SoWhat(sw),stillexists(true),fraction(f)
{
    physicshape = new CollideAll;
    AddObject add;
    add.Add(new CollisionFractionEffect(GetID(),f));
}
void EndOnNoFractionObjects::Step()
{
    if(clock()%1000<20)
        SetMask(1);
    else
        SetMask(0);
    if(!stillexists)
    {
        AddObject add;
        if(SoWhat)
            add.Add(new RoundEnd(Position(0,0),true));
        else
            add.Add(new RoundEnd(Position(0,0),false));
        Destroy();
    }
}
void EndOnNoFractionObjects::draw(sf::RenderTarget & target,sf::RenderStates states) const{}
void EndOnNoFractionObjects::StillExists(bool se)
{
    stillexists = se;
}

