#include "Position.h"

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








