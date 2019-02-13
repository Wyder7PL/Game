#include "TreeCollision.h"

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
