#include "../include/Functions.h"

Position MousePos()
{
    Position pos(Keyboard::MouseX()+GraphicControler::viewinfo.GetX()
                    ,Keyboard::MouseY()+GraphicControler::viewinfo.GetY());
    return pos;
}

sf::Vector2f sfLocalPos(Position pos)
{
    return sf::Vector2f(pos.GetX()-GraphicControler::viewinfo.GetX(),
                           pos.GetY()-GraphicControler::viewinfo.GetY());
}
Position LocalPos(Position pos)
{
    return Position(pos.GetX()-GraphicControler::viewinfo.GetX(),
                           pos.GetY()-GraphicControler::viewinfo.GetY());
}
