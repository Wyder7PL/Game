#include "../include/GUIObjectInfoElement.h"
#include <string>

std::string GUIObjectInfoElement::intToStr(int32_t n)
{
     std::string tmp;
     if(n < 0) {
      tmp = "-";
      n = -n;
     }
     if(n > 9)
      tmp += intToStr(n / 10);
     tmp += n % 10 + 48;
     return tmp;
}

GUIObjectInfoElement::GUIObjectInfoElement()
{
    //ctor
}

GUIObjectInfoElement::~GUIObjectInfoElement(){}

uint32_t GUIObjectInfoElement::GetHeight()
{
    return 0;
}

void GOIEvirtual::Istep(){Step();}
void GOIEvirtual::Idraw(sf::RenderTarget & target,sf::RenderStates states){draw(target,states);}

TextureReferenceIllusion::TextureReferenceIllusion(sf::Texture&t):Ref(t){}
CTextureReferenceIllusion::CTextureReferenceIllusion(const sf::Texture&t):Ref(t){}

GOIEPicture::GOIEPicture(Position pos,Position siz,sf::Color col,const sf::Texture& t)
:Object(pos)
{
    picture.setTexture(t);
    shape.setSize(sf::Vector2f(siz.GetX(),siz.GetY()));
    shape.setFillColor(col);

    picture.setScale((siz.GetX()/100),(siz.GetY()/100));

    physicshape = new Circle(1);
    mask = 0;
}
GOIEPicture::~GOIEPicture(){}


void GOIEPicture::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    picture.setPosition(sfLocalPos(PhysicObject::GetPosition()));
}
void GOIEPicture::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
    target.draw(picture,states);
}

void GOIEPicture::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEPicture::GetHeight()
{
    return shape.getSize().y;
}

void GOIEPicture::SetToDestroy()
{
    Destroy();
}

GOIEText::GOIEText(Position pos,Position siz,sf::Color col,std::string str)
:Object(pos),tex(str,pos,siz,14)
{
    tex.SetColor(sf::Color(180,180,180));
    tex.SetFont(Fonts::baloo);

    shape.setSize(sf::Vector2f(siz.GetX(),siz.GetY()));
    shape.setFillColor(col);

    physicshape = new Circle(1);
    mask = 0;
}
GOIEText::~GOIEText(){}

void GOIEText::Step()
{
    Position pos = LocalPos(PhysicObject::GetPosition());
    shape.setPosition(pos.GetX(),pos.GetY());
    tex.SetPosition(pos);
}
void GOIEText::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
    tex.draw(target,states);
}

void GOIEText::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIEText::GetHeight()
{
    return shape.getSize().y;
}

void GOIEText::SetToDestroy()
{
    Destroy();
}

///
GOIENumber::GOIENumber(Position pos,Position siz,sf::Color col)
:Object(pos),number(0)
{
    tex.setFillColor(sf::Color(180,180,180));
    tex.setFont(Fonts::SMB);
    tex.setCharacterSize(16);

    shape.setSize(sf::Vector2f(siz.GetX(),siz.GetY()));
    shape.setFillColor(col);

    physicshape = new Circle(1);
    mask = 0;
}
GOIENumber::~GOIENumber(){}

void GOIENumber::Step()
{
    tex.setString(intToStr(number));
    Position pos = LocalPos(position);
    shape.setPosition(pos.GetX(),pos.GetY());

    tex.setOrigin(tex.getLocalBounds().width,0);
    tex.setPosition(pos.GetX()+shape.getLocalBounds().width,pos.GetY());
}
void GOIENumber::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    target.draw(shape,states);
    target.draw(tex,states);
}

void GOIENumber::ChangePosition(Position pos)
{
    position = pos;
}

uint32_t GOIENumber::GetHeight()
{
    return shape.getSize().y;
}
uint32_t GOIENumber::GetTextWidth()
{
    return tex.getLocalBounds().width;
}

void GOIENumber::SetToDestroy()
{
    Destroy();
}

void GOIENumber::SetNumber(int32_t i)
{
    number = i;
}

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

///

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












