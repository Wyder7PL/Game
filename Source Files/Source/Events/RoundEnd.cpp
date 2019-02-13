#include "RoundEnd.h"

uint32_t RoundEnd::RoundEndState = 0;

RoundEnd::RoundEnd(Position pos,bool Win)
:Object(pos),TillTheEnd(180)
{
    physicshape = new Circle(1);
    mask = 0;
    SetZIndex(11);

    TheLastThingYouSee.setCharacterSize(128);
    TheLastThingYouSee.setPosition(300,300);
    TheLastThingYouSee.setFont(Fonts::baloo);
    if(Win)
    {
        TheLastThingYouSee.setColor(sf::Color::Blue);
        TheLastThingYouSee.setString("YOU WIN");
    }
    else
    {
        TheLastThingYouSee.setColor(sf::Color::Red);
        TheLastThingYouSee.setString("YOU LOSE");
    }
}
void RoundEnd::Step()
{
    if(TillTheEnd==0)
    {
        RoundEnd::RoundEndState = 1;
        Destroy();
        return;
    }
    else
        TillTheEnd--;
}
void RoundEnd::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(TheLastThingYouSee,states);
}
