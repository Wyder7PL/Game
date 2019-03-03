#include "GOIEPTHorisontal.h"

GOIEPTHorisontal::GOIEPTHorisontal(Position pos,Position siz,Position picsiz,sf::Color col,std::list<CTextureReferenceIllusion> t)
:Object(pos)
{
    border = (siz.GetY()-picsiz.GetY())/2;

    background.setFillColor(sf::Color(30,30,30));
    background.setSize(sf::Vector2f(siz.GetX(),siz.GetY()));

    psx = picsiz.GetX()+border;
    uint32_t i = 0;
    for(std::list <CTextureReferenceIllusion>::const_iterator ite = t.begin();ite!=t.end();ite++)
    {
        GOIEPicture * pic = new GOIEPicture(Position(pos.GetX()+psx*i+border,pos.GetY()+border),picsiz,col,(*ite).Ref);
        pictures.push_back(pic);
        i++;
    }


    physicshape = new Circle(1);
    mask = 0;
}
GOIEPTHorisontal::~GOIEPTHorisontal()
{
    for(std::list <GOIEPicture*>::iterator ite = pictures.begin();ite!=pictures.end();ite++)
    {

    }
}


void GOIEPTHorisontal::Step()
{
    background.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    uint32_t i = 0;
    for(std::list <GOIEPicture*>::iterator ite = pictures.begin();ite!=pictures.end();ite++)
    {
        (*ite)->SetPosition(position.GetX()+psx*i+border,position.GetY()+border);
        (*ite)->Step();
        i++;
    }
}
void GOIEPTHorisontal::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(background,states);
    for(std::list <GOIEPicture*>::const_iterator ite = pictures.begin();ite!=pictures.end();ite++)
        (*ite)->draw(target,states);
}

void GOIEPTHorisontal::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEPTHorisontal::GetHeight()
{
    return background.getSize().y;
}

void GOIEPTHorisontal::SetToDestroy()
{
    Destroy();
    for(std::list <GOIEPicture*>::iterator ite = pictures.begin();ite!=pictures.end();ite++)
    {
        (*ite)->SetToDestroy();
    }
}
