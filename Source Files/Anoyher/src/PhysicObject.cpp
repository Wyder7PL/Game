#include "..\include\PhysicObject.h"

Position::Position(float X,float Y)
:x(X),y(Y)
{

}

Position::Position(const Position & pos)
:x(pos.x),y(pos.y)
{

}

float Position::GetX()
{
    return x;
}

float Position::GetY()
{
    return y;
}

void Position::Set(float X,float Y)
{
    x = X;
    y = Y;
}

void Position::SetX(float X)
{
    x = X;
}

void Position::SetY(float Y)
{
    y = Y;
}

void Position::operator=(const float & pos)
{
    x = pos;
    y = pos;
}

float Position::distance(Position pos)
{
    return powf( powf(pos.GetX()-x,2)+powf(pos.GetY()-y,2),0.5);
}
float Position::angle(Position pos)
{
    return atan2(pos.GetY()-y,pos.GetX()-x);
}
Position Position::GMP(float angle,float distance)
{
    return Position(x+cosf(angle)*distance,y+sinf(angle)*distance);
}

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

void PhysicObject::Collide(PhysicObject*obj)
{
    physicshape->Collide(obj,position);
}
bool PhysicObject::CollideV2(PhysicObject*obj)
{
    return physicshape->CollideV2(obj,position);
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

PhysicShape::~PhysicShape(){};

int32_t PhysicShape::GetShape()
{
    return shape;
}

Position PhysicShape::GetClosestEdge(Position pos1,Position pos2,float d)
{
    return pos1;
}

CollideAll::CollideAll()
{
    shape = 3;
}
CollideAll::~CollideAll(){}

void CollideAll::Collide(PhysicObject*obj,Position pos){return;}

bool CollideAll::CollideV2(PhysicObject*obj,Position pos){return true;}

bool CollideAll::InArea(Position position,Position pos){return true;}

Position CollideAll::GetSize(){return Position(0,0);}

Circle::Circle()
{
    radius = 1;
    shape = 1;
}

Circle::Circle(float Radius)
{
    radius = Radius;
    shape = 1;
}

Circle::~Circle()
{
    //dtor
}

void Circle::Collide(PhysicObject * obj,Position position)
{
    Circle * cir = dynamic_cast<Circle*>(obj->GetShape());
    if(cir != NULL)
    {
        obj->Push(CollideCircle(cir,position,obj->GetPosition()));
        return;
    }
}
bool Circle::CollideV2(PhysicObject * obj,Position position)
{
    Circle * cir = dynamic_cast<Circle*>(obj->GetShape());
    if(cir != NULL)
    {
        return cir->CollideCircleV2(cir,position,obj->GetPosition());
    }
    CollideAll * cal = dynamic_cast<CollideAll*>(obj->GetShape());
    if(cal != NULL)
    {
        return true;
    }
    return false;
}

bool Circle::InArea(Position position,Position pos)
{
    if(radius > pow(pow( position.GetX()-pos.GetX() , 2  ) + pow( position.GetY()-pos.GetY() , 2 ), 0.5f ))
        {
            return true;
        }
        return false;
}

Position Circle::GetClosestEdge(Position pos1,Position pos2,float d)
{
    Position edge(pos2.GetX()+cos(pos2.angle(pos1))*radius*d,pos2.GetY()+sin(pos2.angle(pos1))*radius*d);
    return edge;
}

Position Circle::CollideCircle(Circle * cir,Position position,Position pos)
{
    float rad = cir->GetSize().GetX()/2;
    Position force(0,0);
    float distance = pow(pow( position.GetX()-pos.GetX() , 2  ) + pow( position.GetY()-pos.GetY() , 2 ), 0.5f );
    if(rad+radius > distance)
        {
            float x = pos.GetX()-position.GetX();
            float y = pos.GetY()-position.GetY();
            float radian = 0;
            if(x == 0 && y == 0)
            {
                radian = (rand()%360) *PI/180;
                force.Set(radian,20.0);
                return force;
            }
            if(x == 0)
            {
                if(y < 0)
                    radian = 3*PI/2;
                else
                    radian = PI/2;
            }
            else if(y == 0 && x < 0)
                radian = PI;
            else
                radian = atan2f( y,x );
            force.Set(radian,2.0*distance/(rad+radius) );
        }
        return force;
}
bool Circle::CollideCircleV2(Circle * cir,Position position,Position pos)
{
    float rad = cir->GetSize().GetX()/2;
    float distance = pow(pow( position.GetX()-pos.GetX() , 2  ) + pow( position.GetY()-pos.GetY() , 2 ), 0.5f );
    if(rad+radius > distance)
        {
            return true;
        }
        return false;
}
bool Circle::CollideAllV2(CollideAll * cir,Position position,Position pos)
{
    return true;
}


void Circle::SetRadius(float Rad)
{
    radius = Rad;
}


Position Circle::GetSize()
{
    Position ppp(0,0);
    ppp=radius*2.0f;
    return ppp;
}

/// /////////////////////////// ///
/// /////////////////////////// ///
/// /////////////////////////// ///

NRR::NRR()
:dimensions(Position(1,1))
{
    shape = 2;
}

NRR::NRR(Position s)
:dimensions(s)
{
    shape = 2;
}

NRR::~NRR(){}

void NRR::Collide(PhysicObject * obj,Position position)
{
    Circle * cir = dynamic_cast<Circle*>(obj->GetShape());
    if(cir != NULL)
    {
        obj->Push(CollideCircle(cir,position,obj->GetPosition()));
        return;
    }
}
bool NRR::CollideV2(PhysicObject * obj,Position position)
{
    return false;
}

bool NRR::InArea(Position position,Position pos)
{
    if(position.GetX()<pos.GetX() && position.GetX()+dimensions.GetX()>pos.GetX())
    {
        if(position.GetY()<pos.GetY() && position.GetY()+dimensions.GetY()>pos.GetY())
            return true;
    }
    return false;
}

Position NRR::CollideCircle(Circle * cir,Position position,Position pos)
{
    Position force(0,0);
    return force;
}
bool NRR::CollideCircleV2(Circle * cir,Position position,Position pos)
{
    return false;
}

void NRR::SetSize(Position s)
{
    dimensions = s;
}

Position NRR::GetSize()
{
    return dimensions;
}

















