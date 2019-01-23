#include "../include/NaturalResource.h"

NaturalResource::NaturalResource(Position pos,uint32_t Rtype)
:NonClickable(pos),RAv(Rtype)
{
    RDPointer = new list_pointer(&RDV);
    RDV.push_back(&RAv);
}

NaturalResource::~NaturalResource()
{
    RDPointer->TurnOff();
}

ResourceAvailability::ResourceAvailability(uint32_t t):type(t){}
uint32_t ResourceAvailability::GetAmount(){return amoumt;}
uint32_t ResourceAvailability::GetType(){return type;}
void ResourceAvailability::SetAmount(uint32_t a){amoumt = a;}
void ResourceAvailability::SetType(uint32_t t){type = t;}

TreeCollision::TreeCollision(uint32_t a,float t)
:position(0,0),TrunkRadius(t)
{
    affected = a;
}
TreeCollision::~TreeCollision(){}

void TreeCollision::Step(ObjectInserter& ins,Object* obj)
{
    position = obj->GetPosition();
}
void TreeCollision::OnCollision(ObjectInserter& ins,Object* obj)
{
    if(dynamic_cast<Markable*>(obj)!=NULL&&position.distance(obj->GetClosestEdge(position,1))<TrunkRadius)
        obj->Push(Position(atan2(obj->GetPosition().GetY()-position.GetY(),obj->GetPosition().GetX()-position.GetX()),6.0));
}


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
