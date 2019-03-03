#include "MarkUnit.h"


MultiUnitSelection * MarkUnit::MUS = NULL;

void MarkUnit::CreateMUS(MultiUnitSelection * m)
{
    MUS = m;
    AddObject add;
    add.Add(MUS);
}

MarkUnit::MarkUnit(Position pos)
:Markable(pos),pervious(false)
,ntm(false),ntmdenycooldown(0),Destination(0,0)
{
    mark.setRadius(20);
    mark.setOrigin(15,15);
    mark.setOutlineThickness(5);
    mark.setOutlineColor(sf::Color(150,150,150,100));
    mark.setFillColor(sf::Color(180,180,180));

    physicshape = new Circle(10);
    mask = 1;
}
MarkUnit::~MarkUnit()
{
    if(selected)
        MUS->decrease();
}

void MarkUnit::Step()
{
    if(MUS->AreSelected())
    {
        if(MUS->AfterSelect() && GetFraction() == 2 && MUS->InArea(position) && !pervious)
        {
            MUS->increase();
            pervious = true;
            selected = true;
        }
        if(selected && Keyboard::MousePP())
        {
            ntm = true;
            Destination = MousePos();
        }
        if(selected){
            uint32_t i = MUS->GetSkillTypeButtonState(),j = GetSkillType(),k = i&j;
            if(i!=0&&k==0)
                QuickDeselect();
        }
    }
    else if(pervious)
        QuickDeselect();

    if(position.distance(Destination)<30)
    {
        if(ntmdenycooldown>0)
            ntmdenycooldown--;
        else
            ntm = false;
    }


    mark.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    if(selected)
        mark.setOutlineColor(sf::Color(150,150,150));
    else
    mark.setOutlineColor(sf::Color(0,0,0,0));

    Markable::Step();
}
void MarkUnit::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    Markable::draw(target,states);
    target.draw(mark,states);
}

void MarkUnit::MarkSize(float siz)
{
    mark.setRadius(siz);
    mark.setOrigin(siz,siz);
    mark.setOutlineThickness(5);
    mark.setOutlineColor(sf::Color(150,150,150));
}

void MarkUnit::CreateInfo(std::list<Info>& Objects)
{
    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 20;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}

void MarkUnit::Desactivate()
{
    Object::Desactivate();
    if(selected)
    {
        MUS->decrease();
        selected = false;
    }
}

bool MarkUnit::ForcedMove()
{
    return ntm;
}
Position MarkUnit::ForcedDestination()
{
    return Destination;
}
void MarkUnit::ForceDestination(Position pos)
{
    ntm = true;
    ntmdenycooldown = 5;
    Destination = pos;
}
void MarkUnit::QuickDeselect()
{
    pervious = false;
    selected = false;
    MUS->decrease();
}
