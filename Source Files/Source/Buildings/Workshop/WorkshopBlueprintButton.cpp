#include "WorkshopBlueprintButton.h"

WorkshopBlueprintButton::WorkshopBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(70,50,90));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void WorkshopBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void WorkshopBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void WorkshopBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tworkshop,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Workshop");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBWorkshop * ttt = new OICBWorkshop(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
