#include "CollisionFractionEffect.h"

CollisionFractionEffect::CollisionFractionEffect(uint32_t a,uint32_t f)
:fraction(f),collided(false),AfterCollision(false)
{
    affected = a;
}
void CollisionFractionEffect::OnCollision(ObjectInserter & ins,Object * obj)
{
    if(!AfterCollision)
        AfterCollision=true;
    if(collided)
        return;
    Markable * m = dynamic_cast<Markable*>(obj);
    if(m!=NULL&&m->GetFraction()==fraction)
        collided = true;

}
void CollisionFractionEffect::Step(ObjectInserter & ins,Object * obj)
{
    if(AfterCollision)
    {
        AfterCollision=false;
        EndOnNoFractionObjects * eonfo = dynamic_cast<EndOnNoFractionObjects*>(obj);
        if(eonfo!=NULL)
            eonfo->StillExists(collided);
        collided=false;
    }
}
