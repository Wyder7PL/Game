#include "../include/ObjectInfo.h"

ObjectInfo::ObjectInfo()
{
    //ctor
}

ObjectInfo::~ObjectInfo()
{
    //dtor
}

GUIObjectInfoElement * ObjectInfo::Create(Position pos){return NULL;}

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

OIText::OIText(Position dimension,sf::Color color,std::string s)
:wAh(dimension),col(color),str(s)
{

}

Position OIText::GetWah()
{
    return wAh;
}
sf::Color OIText::GetCol()
{
    return col;
}
std::string OIText::GetStr()
{
    return str;
}

GUIObjectInfoElement * OIText::Create(Position pos)
{
    return new GOIEText(pos,wAh,col,str);
}

OINumber::OINumber(Position dimensions,sf::Color color,int32_t number)
:wAh(dimensions),col(color),num(number)
{

}

GUIObjectInfoElement * OINumber::Create(Position pos)
{
    GOIENumber * obj = new GOIENumber(pos,wAh,col);
    obj->SetNumber(num);
    return obj;
}

OIPointedu32::OIPointedu32(uint32_t_pointer * pointer,OINumber number)
:poi(pointer),num(number)
{

}

GUIObjectInfoElement * OIPointedu32::Create(Position pos)
{
    GOIEPointed * obj = new GOIEPointed(pos,*dynamic_cast<GOIENumber*>(num.Create(pos)),poi);
    obj->SetNumber(*poi->GetPointer());
    return obj;
}

OIPT::OIPT(Position dimension1,sf::Color color1,sf::Texture & t,Position dimension2,sf::Color color2,std::string str)
:pic(dimension1,color1,t),tex(dimension2,color2,str)
{

}

GUIObjectInfoElement * OIPT::Create(Position pos)
{
    return new GOIEPT(pos,pic.GetWah(),pic.GetCol(),pic.GetTexture(),
                      tex.GetWah(),tex.GetCol(),tex.GetStr());
}


















