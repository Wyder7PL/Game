#include "GlobalEvents.h"

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
        TheLastThingYouSee.setFillColor(sf::Color::Blue);
        TheLastThingYouSee.setString("YOU WIN");
    }
    else
    {
        TheLastThingYouSee.setFillColor(sf::Color::Red);
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

OnBarracksDestroy::OnBarracksDestroy(Position pos,uint32_t f,std::list<BarrackUnitStorage> bus,bool what)
:Barracks(pos,f,bus),OnBuildingDestroy(what){}

MagazineSurvive::MagazineSurvive(Position pos,uint32_t f,bool what,uint32_t SurvivalTime)
:Magazine(pos,f),BuildingSurvive(what,SurvivalTime)
{

}
void MagazineSurvive::Step()
{
    Magazine::Step();
    BuildingSurvive::Step();
}

CollisionFractionEffect::CollisionFractionEffect(uint32_t a,uint32_t f)
:fraction(f),collided(false),AfterCollision(false)
{
    affected = a;
}
void CollisionFractionEffect::OnCollision(ObjectInserter & ins,Object * obj)
{
    if(!AfterCollision)
        AfterCollision=true;
    if(collided)
        return;
    Markable * m = dynamic_cast<Markable*>(obj);
    if(m!=NULL&&m->GetFraction()==fraction)
        collided = true;

}
void CollisionFractionEffect::Step(ObjectInserter & ins,Object * obj)
{
    if(AfterCollision)
    {
        AfterCollision=false;
        EndOnNoFractionObjects * eonfo = dynamic_cast<EndOnNoFractionObjects*>(obj);
        if(eonfo!=NULL)
            eonfo->StillExists(collided);
        collided=false;
    }
}

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

