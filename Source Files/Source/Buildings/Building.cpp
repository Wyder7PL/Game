#include "Building.h"

Building::Building(Position pos,uint32_t f)
:MarkBuilding(pos),GUIHPPoint(NULL),GUIMHPPoint(NULL),fraction(f)
{
    PhysicObject::SetPosition(pos.GetX(),pos.GetY());

    shape.setSize(sf::Vector2f(30,30));
    shape.setOrigin(15,15);
    shape.setOutlineThickness(10);
    shape.setFillColor(sf::Color(50,50,50));
    shape.setOutlineColor((*Fraction::Fractions)[f]->GetFractionColor());

    mark.setOrigin(50,50);
    mark.scale(0.4,0.4);

    physicshape = new Circle(25);
    mask = 1;
    SetMass(0);
    SetMaxSpeed(5);
    stopping=0.2;

    MarkBuilding::MarkSize(25);

    OutHP = new WoodenHP(60);
    InHP = new HP(50);
}

Building::~Building()
{
    if(GUIHPPoint != NULL)
    {
        GUIHPPoint->TurnOff();
        GUIHPPoint = NULL;
    }
    if(GUIMHPPoint != NULL)
    {
        GUIMHPPoint->TurnOff();
        GUIMHPPoint = NULL;
    }
}

void Building::Step()
{
    if(FirstStep())
    {
        Collision * col = new Collision(GetID());
        AddObject add;
        add.Add(col);
    }

    MarkBuilding::Step();
    AllHP = OutHP->GetHP() + InHP->GetHP();
    FullHP = OutHP->GetMaxHP() + InHP->GetMaxHP();
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    mark.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    if(OutHP->GetHP()+InHP->GetHP() < 0)
    {
        Destroy();
        if(selected)
        {
            SetSelectedType(0);
            GUIHPPoint->TurnOff();
            GUIHPPoint = NULL;
            GUIMHPPoint->TurnOff();
            GUIMHPPoint = NULL;
        }
    }
}
void Building::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    MarkBuilding::draw(target,states);
    target.draw(shape,states);
    target.draw(mark,states);
}

void Building::Selected()
{
    MarkBuilding::Selected();

    SetHPonGUI();
}

void Building::DealDamage(uint32_t damage,uint32_t type)
{
    if(OutHP->GetHP()==0||rand()%4==0)
        InHP->TakeDamage(damage,type);
    else
        OutHP->TakeDamage(damage,type);
}

uint32_t Building::GetFraction()
{
    return fraction;
}

void Building::CreateInfo(std::list<Info>& Objects)
{
    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 1;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}

void Building::SetHPonGUI()
{
    GUIHPPoint = new uint32_t_pointer(&AllHP);
    GUIMHPPoint = new uint32_t_pointer(&FullHP);
    SafePointer::Pointers.push_back(GUIHPPoint);
    SafePointer::Pointers.push_back(GUIMHPPoint);
    OIBar * p32 = new OIBar(GUIHPPoint,GUIMHPPoint,sf::Color::Red,150);
    Markable::MarkedObjectInfo.Information.push_back(p32);
}

