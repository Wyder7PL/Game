#include "GOIEPT.h"


GOIEPT::GOIEPT(Position pos,Position siz1,sf::Color col1,sf::Texture& t,Position siz2,sf::Color col2,std::string str)
:Object(pos),pic(pos,siz1,col1,t),tex(Position(pos.GetX()+siz1.GetX()+5,pos.GetY()),siz2,col2,str)
{
    physicshape = new Circle(1);
    mask = 0;
}
GOIEPT::~GOIEPT(){}

void GOIEPT::Step()
{
    Position pos = GetPosition();
    pic.SetPosition(pos.GetX(),pos.GetY());
    pic.Step();
    tex.SetPosition(pos.GetX()+55,pos.GetY());
    tex.Step();
}
void GOIEPT::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    pic.draw(target,states);
    tex.draw(target,states);
}

void GOIEPT::ChangePosition(Position pos)
{
    position = pos;
    pic.ChangePosition(pos);
    tex.ChangePosition(pos);
}

uint32_t GOIEPT::GetHeight()
{
    return pic.GetHeight();
}

void GOIEPT::SetToDestroy()
{
    pic.SetToDestroy();
    tex.SetToDestroy();
    Destroy();
}


