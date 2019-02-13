#include "Sight.h"

Sight::Sight(Position pos,float range)
:Object(pos),ready(false),destroy(false)
{
    physicshape = new Circle(range);
    mask = 1;
}

void Sight::Step()
{
    if(destroy)
        Destroy();
}

void Sight::draw(sf::RenderTarget & target,sf::RenderStates states) const{}

void Sight::SetReady()
{
    ready = true;
}

bool Sight::Ready()
{
    return ready;
}

void Sight::Erase()
{
    Objects.clear();
    destroy = true;
}
