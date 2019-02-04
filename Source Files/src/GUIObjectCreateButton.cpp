#include "../include/GUIObjectCreateButton.h"

GOITESTCREATE::GOITESTCREATE(Position pos,Position dim,GOIEText t,uint32_t fraction)
:Clickable2(pos),tex(t),PlayerFraction(fraction)
{
    physicshape = new NRR(dim);
    mask = 0;
}
GOITESTCREATE::~GOITESTCREATE(){}

void GOITESTCREATE::Istep(){Step();}
void GOITESTCREATE::Idraw(sf::RenderTarget & target,sf::RenderStates states){draw(target,states);}
void GOITESTCREATE::Step()
{
    Clickable2::Step();
    Position pos = GetPosition();
    tex.SetPosition(pos.GetX(),pos.GetY());
    tex.Step();
}
void GOITESTCREATE::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Clickable2::draw(target,states);
    tex.draw(target,states);
}

void GOITESTCREATE::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOITESTCREATE::GetHeight()
{
    return tex.GetHeight();
}

void GOITESTCREATE::SetToDestroy()
{
    tex.SetToDestroy();
    Destroy();
}

void GOITESTCREATE::Selected()
{
    if(Markable::GetSelectedType() != 4)
    {
        Markable::SetSelectedType(4);
        BuildingConstruction * b = new BuildingConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
        b->TESTCreateDemand(1,10);
        PreBuilding * p = new PreBuilding(position,b);
        AddObject a;
        a.Add(p);
    }
}





OITest::OITest(OIText t,uint32_t pfr)
:tex(t),PlayerFraction(pfr)
{

}

OIText OITest::GetTex()
{
    return tex;
}

GUIObjectInfoElement * OITest::Create(Position pos)
{
    return new GOITESTCREATE(pos,tex.GetWah(),*static_cast<GOIEText*>(tex.Create(pos)),PlayerFraction);
}
















