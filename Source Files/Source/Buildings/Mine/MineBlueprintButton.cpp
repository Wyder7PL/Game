#include "MineBlueprintButton.h"

MineBlueprintButton::MineBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(100,100,100));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void MineBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void MineBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void MineBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tmine,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Mine");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBMine * ttt = new OICBMine(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
