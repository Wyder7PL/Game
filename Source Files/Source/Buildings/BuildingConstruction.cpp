#include "BuildingConstruction.h"

BuildingConstruction::BuildingConstruction(Position pos,uint32_t f)
:Construction(pos,f)
{
    physicshape = new Circle(25);
    mask = 1;
    SetMass(0);
    SetZIndex(6);

    shape.setSize(sf::Vector2f(30,30));
    shape.setOrigin(15,15);
    shape.setOutlineThickness(10);
    shape.setFillColor(sf::Color(255,255,255));
    shape.setOutlineColor(sf::Color(235,233,188));

    ConstructionHP = new WoodenHP(50);

}
BuildingConstruction::~BuildingConstruction()
{

}
void BuildingConstruction::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    Construction::Step();
}
void BuildingConstruction::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    MarkBuilding::draw(target,states);
    target.draw(shape,states);
}
void BuildingConstruction::Create()
{
    AddObject add;
    Building * b = new Building(position);
    add.Add(b);
}
void BuildingConstruction::CreateInfo(std::list<Info>& Objects)
{
    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 2;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    inf.lpointer = RDPointer;
    Objects.push_back(inf);
}

void BuildingConstruction::TESTCreateDemand(uint32_t typ,uint32_t amount)
{
    ResourceDemand r(typ,amount);
    ResourcesDemanded.push_back(r);
    for(std::list <ResourceDemand>::iterator ite = ResourcesDemanded.begin();ite != ResourcesDemanded.end();ite++)
    {
        RDV.push_back(&(*ite));
    }
}
