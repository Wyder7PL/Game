#include "PhysicObject.h"



PhysicObject::PhysicObject(Position  pos)
:position(pos),toClear(false),Force(0,0),AditionalForce(0,0),speed(5.0),mass(1.0),braking(0)
{
    VectorID = 0;
    physicshape = NULL;

    stopping = 0.02;
}

PhysicObject::~PhysicObject()
{
    delete physicshape;
}

bool PhysicObject::CollideV2(PhysicObject*obj)
{
    return physicshape->CollideV2(obj->GetShape(),obj->GetPosition(),position);
}

bool PhysicObject::InArea(Position pos)
{
    return physicshape->InArea(position,pos);
}

void PhysicObject::ApplyStoredForces()
{
    if(Force.GetY()==0)
        return;

    float x = 0;
    float y = 0;
    if(Force.GetY() > powf(speed,2))
    {
        float slow = powf(Force.GetY(),0.5);
        x = cos(Force.GetX())*slow;
        y = sin(Force.GetX())*slow;
        Force.SetY(Force.GetY()-slow);
    }
    else if(Force.GetY() > speed)
    {
        x = cos(Force.GetX())*speed;
        y = sin(Force.GetX())*speed;
        Force.SetY(Force.GetY()-speed);

    }
    else if(Force.GetY() >= stopping*5)
    {
        x = cos(Force.GetX())*braking;
        y = sin(Force.GetX())*braking;
        Force.SetY(Force.GetY()-stopping);
        braking-=stopping;
    }
    else
    {
        float ax = cos(AditionalForce.GetX())*AditionalForce.GetY();
        float ay = sin(AditionalForce.GetX())*AditionalForce.GetY();
        ax += cos(Force.GetX())*Force.GetY();
        ay += sin(Force.GetX())*Force.GetY();
        AditionalForce.Set(atan2(ay,ax),powf(powf(ax,2)+powf(ay,2),0.5));
        Force.Set(0,0);
        if(AditionalForce.GetY() > 1)
        {
            x += cos(AditionalForce.GetX())*speed;
            y += sin(AditionalForce.GetX())*speed;
            AditionalForce.SetY(AditionalForce.GetY()-speed);
        }
    }
    position.SetX(position.GetX()+x);
    position.SetY(position.GetY()+y);
}

void PhysicObject::Push(Position force)
{
    if(mass == 0)
        return;
    force.SetY(force.GetY()/mass);
    float x = cos(Force.GetX())*Force.GetY();
    float y = sin(Force.GetX())*Force.GetY();
    x += cos(force.GetX())*force.GetY();
    y += sin(force.GetX())*force.GetY();
    Force.Set(atan2(y,x),powf(powf(x,2)+powf(y,2),0.5));
    if(Force.GetY() > speed)
        braking = speed;
    else
        braking = Force.GetY();
}


Position PhysicObject::GetPosition()
{
    return position;
}
void PhysicObject::SetPosition(float x,float y)
{
    position.Set(x,y);
}

Position PhysicObject::GetClosestEdge(Position pos,float d = 1.0)
{
    return physicshape->GetClosestEdge(position,pos,d);
}

uint32_t PhysicObject::GetMask()
{
    return mask;
}
void PhysicObject::SetMask(uint32_t NewMask)
{
    mask = NewMask;
}

PhysicShape * PhysicObject::GetShape()
{
    return physicshape;
}

bool PhysicObject::ToClear()
{
    return toClear;
}

void PhysicObject::SetMass(float m)
{
    mass = m;
}
void PhysicObject::SetMaxSpeed(float s)
{
    speed = s;
}

float PhysicObject::GetMass()
{
    return mass;
}



