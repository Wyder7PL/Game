#include "Collision.h"

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
