#include "OIPT.h"

OIPT::OIPT(Position dimension1,sf::Color color1,sf::Texture & t,Position dimension2,sf::Color color2,std::string str)
:pic(dimension1,color1,t),tex(dimension2,color2,str)
{

}

GUIObjectInfoElement * OIPT::Create(Position pos)
{
    return new GOIEPT(pos,pic.GetWah(),pic.GetCol(),pic.GetTexture(),
                      tex.GetWah(),tex.GetCol(),tex.GetStr());
}

