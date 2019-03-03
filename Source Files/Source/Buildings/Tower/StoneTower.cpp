#include "StoneTower.h"

StoneTower::StoneTower(Position pos,uint32_t f):Tower(pos,f)
{

    delete OutHP;
    OutHP = new HP(150,150);

    shape.setFillColor(sf::Color(170,170,170));

}
