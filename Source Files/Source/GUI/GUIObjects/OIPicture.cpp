#include "OIPicture.h"


OIPicture::OIPicture(Position dimension,sf::Color color,sf::Texture& t)
:wAh(dimension),col(color),tex(t)
{

}

Position OIPicture::GetWah()
{
    return wAh;
}
sf::Color OIPicture::GetCol()
{
    return col;
}
sf::Texture & OIPicture::GetTexture()
{
    return tex;
}

GUIObjectInfoElement * OIPicture::Create(Position pos)
{
    return new GOIEPicture(pos,wAh,col,tex);
}

