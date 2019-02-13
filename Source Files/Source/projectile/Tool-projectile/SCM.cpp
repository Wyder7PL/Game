#include "SCM.h"

SCM::SCM(SCMEff * eff,uint32_t f)
:projectile(Position(0,0),f)
{
    eff->ChangeAffected(GetID());
    AddObject add;
    add.Add(eff);
    physicshape = new CollideAll();
    mask = 1;
}
SCM::~SCM()
{
    //dtor
}
void SCM::Step()
{
    Destroy();
}
void SCM::draw(sf::RenderTarget & target,sf::RenderStates states) const{}
