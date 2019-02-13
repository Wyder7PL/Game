#include "GUI.h"

GUI::GUI()
:Object(Position(0,0))
{
    SetZIndex(7);
    SetPlayerFraction(2);
    ConnectFractionToObjects();

    BlueprintButtons.SetButtons();

    background.setSize(sf::Vector2f(175,786));
    background.setFillColor(sf::Color(50,50,50));

    for(uint32_t i = 0;i < 2;i++)
    {
        lines[i].setSize(sf::Vector2f(155,2));
        lines[i].setFillColor(sf::Color(0,0,0));
    }


    physicshape = new Circle(50);
    mask = 0;
}

GUI::~GUI()
{
    DestroyElements();
}

void GUI::DestroyElements()
{

}

void GUI::Step()
{
    PhysicObject::SetPosition(GraphicControler::viewinfo.GetX(),GraphicControler::viewinfo.GetY());
    Position pos = PhysicObject::GetPosition();
    background.setPosition(sfLocalPos(pos));
    for(uint32_t i = 0;i < 2;i++)
    {
        lines[i].setPosition(10+sfLocalPos(pos).x,
                             250+i*250+sfLocalPos(pos).y);
    }
    Resources.SetPosition(pos.GetX(),pos.GetY());
    Resources.Step();

    BlueprintButtons.SetPosition(pos.GetX(),pos.GetY()+250);
    BlueprintButtons.Step();

    ObjectsInfo.SetPosition(pos.GetX(),pos.GetY()+500);
    ObjectsInfo.Step();
}
void GUI::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(background,states);
    target.draw(lines[0],states);
    target.draw(lines[1],states);

    Resources.draw(target,states);
    BlueprintButtons.draw(target,states);
    ObjectsInfo.draw(target,states);
}

void GUI::Refresh()
{
    ObjectsInfo.Refresh();
}

void GUI::SetPlayerFraction(uint32_t f)
{
    PlayerFraction = f;
}

void GUI::ConnectFractionToObjects()
{
    Resources.SetPlayerFraction(&PlayerFraction);
    BlueprintButtons.SetPlayerFraction(&PlayerFraction);
    ObjectsInfo.SetPlayerFraction(&PlayerFraction);
}












