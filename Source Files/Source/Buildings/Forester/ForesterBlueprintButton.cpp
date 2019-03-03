#include "ForesterBlueprintButton.h"

ForesterBlueprintButton::ForesterBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(20,200,20));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void ForesterBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void ForesterBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void ForesterBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tforester,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Forester");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBForester * ttt = new OICBForester(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
