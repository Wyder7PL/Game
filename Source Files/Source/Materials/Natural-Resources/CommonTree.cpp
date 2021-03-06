#include "CommonTree.h"

CommonTree::CommonTree(Position pos)
:NaturalResource(pos,1),hp(new WoodenHP(50))
{
    shape.setRadius(25);
    shape.setOrigin(25,25);
    shape.setFillColor(sf::Color(50,150,50));

    physicshape = new Circle(25);
    mask = 1;
    SetMass(0);

}

CommonTree::~CommonTree(){delete hp;}

void CommonTree::Step()
{
    if(FirstStep())
    {
        TreeCollision * col = new TreeCollision(GetID(),8);
        AddObject add;
        add.Add(col);
        if(SetGrid(position,GetShape()->GetSize()))
            Destroy();
    }
    Markable::Step();
    if(hp->GetHP() <= 0)
        Destroy();
    hphandle = (hp->GetHP()-hp->GetHP()%5)/5;
    RAv.SetAmount(hphandle);
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}

void CommonTree::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
}

bool CommonTree::TakeResource()
{
    if(hp->GetHP()>0)
    {
        DealDamage(5,0);
        return true;
    }
    return false;
}

void CommonTree::DealDamage(uint32_t damage,uint32_t type)
{
    hp->TakeDamage(damage,type);
}

void CommonTree::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 101;
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    inf.lpointer = RDPointer;
    Objects.push_back(inf);
}
