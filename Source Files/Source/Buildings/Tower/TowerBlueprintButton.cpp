#include "TowerBlueprintButton.h"

TowerBlueprintButton::TowerBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(0,0,0));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void TowerBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void TowerBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void TowerBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Ttower,
                               Position(100,50),sf::Color(30,30,30),"Combat Tower");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBTower * ttt = new OICBTower(OIText(Position(150,50),sf::Color(130,30,30),"CREATE Wooden Tower"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
    OICBStoneTower * tt2 = new OICBStoneTower(OIText(Position(150,50),sf::Color(130,30,30),"CREATE Stone Tower"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(tt2);
}
