#include "Tasks.h"

Offense1Task::Offense1Task(uint32_t id,std::list <Position> chk)
:UnitTask(id),CheckPoints(chk)
{

}
Offense1Task::~Offense1Task(){}
void Offense1Task::Step(ObjectInserter & Inserter,Object * obj)
{
    if(CheckPoints.size()==0)
    {
        SetToClear();
        return;
    }
    Unit * uni = dynamic_cast<Unit*>(obj);
    if(uni != NULL)
    {
        Position pos = uni->GetPosition();
        if(pos.distance((*CheckPoints.begin()))<30)
        {
            CheckPoints.erase(CheckPoints.begin());
            return;
        }
        else
        {
            uni->ForceDestination((*CheckPoints.begin()));
            uni->ForceToIgnoreEnemy(false);
        }
    }
}

CreateUnitsOnAproach::CreateUnitsOnAproach(uint32_t id,std::list <BarrackUnitStorage> bus)
:UnitTask(id),Approached(false),BUS(bus){}

CreateUnitsOnAproach::~CreateUnitsOnAproach()
{
    for(std::list <BarrackUnitStorage>::iterator ite = BUS.begin();ite != BUS.end();ite++)
    {
        for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
            delete (*ite2);
        delete (*ite).warrior;
    }
}
void CreateUnitsOnAproach::SetApproached()
{
    Approached = true;
}

void CreateUnitsOnAproach::Step(ObjectInserter & Inserter,Object * obj)
{
    if(BUS.size()==0)
    {
        SetToClear();
        CUOAScanObject * scn = dynamic_cast<CUOAScanObject*>(obj);
        if(scn!=NULL)
            scn->SetToDestroy();
    }
    if(Approached)
    {
        for(std::list <BarrackUnitStorage>::iterator ite = BUS.begin();ite != BUS.end();)
        {
            if((*ite).RelaseTime==0)
            {
                Inserter.AddObject((*ite).warrior);
                for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
                    Inserter.AddEffect((*ite2));
                ite = BUS.erase(ite);
            }
            else
            {
                (*ite).RelaseTime--;
                ite++;
            }
        }
    }
}

CreateUnitsOnIDAproach::CreateUnitsOnIDAproach(uint32_t id,std::list <BarrackUnitStorage> bus,uint32_t tid)
:CreateUnitsOnAproach(id,bus),TargetID(tid)
{

}
void CreateUnitsOnIDAproach::OnCollision(ObjectInserter & Inserter,Object * obj)
{
    if(obj->GetID()==TargetID)
        SetApproached();
}

CreateUnitsOnFractionAproach::CreateUnitsOnFractionAproach(uint32_t id,std::list <BarrackUnitStorage> bus,uint32_t tfr)
:CreateUnitsOnAproach(id,bus),TargetFraction(tfr)
{

}
void CreateUnitsOnFractionAproach::OnCollision(ObjectInserter & Inserter,Object * obj)
{
    Unit * uuu = dynamic_cast<Unit*>(obj);
    if(uuu!=NULL && uuu->GetFraction()==TargetFraction)
        SetApproached();
}

CUOAScanObject::CUOAScanObject(Position pos,float range)
:Object(pos)
{
    physicshape = new Circle(range/2);
    mask = 1;
    SetZIndex(10);

    PhysicObject::SetPosition(pos.GetX(),pos.GetY());

    temp.setPosition(position.GetX(),position.GetY());
    temp.setOrigin(range,range);
    temp.setRadius(range);
    temp.setFillColor(sf::Color(20,20,20,20));
}

void CUOAScanObject::SetToDestroy()
{
    Destroy();
}

void CUOAScanObject::Step()
{
    temp.setPosition(sfLocalPos(position));
}
void CUOAScanObject::draw(sf::RenderTarget & target,sf::RenderStates states) const{}
