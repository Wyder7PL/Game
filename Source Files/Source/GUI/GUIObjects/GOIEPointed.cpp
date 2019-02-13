#include "GOIEPointed.h"

GOIEPointed::GOIEPointed(Position pos,Position siz,sf::Color col,uint32_t_pointer * poi)
:GOIENumber(pos,siz,col),pointer(poi)
{

}
GOIEPointed::GOIEPointed(Position pos,GOIENumber num,uint32_t_pointer * poi)
:GOIENumber(num),pointer(poi)
{

}
GOIEPointed::GOIEPointed(GOIEPointed & rek)
:GOIENumber(rek)
{
    pointer = rek.pointer;
}
GOIEPointed::~GOIEPointed(){}

void GOIEPointed::Step()
{
    if(pointer == NULL )
        SetNumber(0);
    else if(pointer->DestroyMe())
        pointer = NULL;
    else
        SetNumber(*pointer->GetPointer());
    GOIENumber::Step();
}
void GOIEPointed::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    GOIENumber::draw(target,states);
}

void GOIEPointed::SetToDestroy()
{
    Destroy();
}
