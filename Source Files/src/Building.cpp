#include "../include/Building.h"

Collision::Collision(uint32_t a)
:position(0,0)
{
    affected = a;
}
Collision::~Collision(){}

void Collision::Step(ObjectInserter& ins,Object* obj)
{
    position = obj->GetPosition();
}
void Collision::OnCollision(ObjectInserter& ins,Object* obj)
{
    if(dynamic_cast<Markable*>(obj)!=NULL)
        obj->Push(Position(atan2(obj->GetPosition().GetY()-position.GetY(),obj->GetPosition().GetX()-position.GetX()),6.0));
}

Building::Building(Position pos,uint32_t f = 0)
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

BuildingBlueprintButton::BuildingBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(20,20,20));
    physicshape = new NRR(Position(15,15));
    mask = 0;
}
BuildingBlueprintButton::~BuildingBlueprintButton()
{

}
void BuildingBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void BuildingBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void BuildingBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Tmagazine,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Tower");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OITest * ttt = new OITest(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}

