#include "Circle.h"


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

bool Circle::CollideV2(PhysicShape * obj,Position position1,Position position2)
{
    Circle * cir = dynamic_cast<Circle*>(obj);
    if(cir != NULL)
    {
        return cir->CollideCircleV2(cir,position2,position1);
    }
    CollideAll * cal = dynamic_cast<CollideAll*>(obj);
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

