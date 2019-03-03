#include "Markable.h"

uint32_t Markable::SelectedType = 0;

uint32_t Markable::GetSelectedType()
{
    return Markable::SelectedType;
}

void Markable::SetSelectedType(uint32_t type)
{
    Markable::SelectedType = type;
}

void Markable::RestartSelectedType()
{
    if(Markable::SelectedType == 5)
        Markable::SelectedType = 3;
}

ObjectInfoStorage Markable::MarkedObjectInfo;

Markable::Markable(Position pos)
:Object(pos),firststep(true)
{
    PhysicObject::SetPosition(pos.GetX(),pos.GetY());
    SetZIndex(5);
    selected = false;
}

Markable::~Markable()
{
    //dtor
}
uint32_t Markable::GetFraction(){return 0;}

void Markable::Step(){if(FirstStep()){firststep = false;}}
void Markable::draw(sf::RenderTarget & target,sf::RenderStates states) const{}

void Markable::DealDamage(uint32_t d,uint32_t t){}

void Markable::CreateInfo(std::list <Info>& Objects){}

bool Markable::FirstStep(){return firststep;}
