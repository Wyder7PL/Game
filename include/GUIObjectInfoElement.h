#ifndef GUIOBJECTINFOELEMENT_H
#define GUIOBJECTINFOELEMENT_H

#include "../Fonts/Fonts.h"
#include "SafePointer.h"
#include "WrapedText.h"
#include "Functions.h"

class GUIObjectInfoElement
{
    public:
        GUIObjectInfoElement();
        virtual ~GUIObjectInfoElement();
        virtual void Istep()=0;
        virtual void Idraw(sf::RenderTarget & target,sf::RenderStates states)=0;
        virtual uint32_t GetHeight();
        virtual void SetToDestroy()=0;
        virtual void ChangePosition(Position)=0;
        std::string intToStr(int32_t);
    protected:
    private:
};

class GOIEvirtual:public GUIObjectInfoElement
{
    virtual void Istep();
    virtual void Idraw(sf::RenderTarget & target,sf::RenderStates states);
    virtual void Step()=0;
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const=0;
};

struct TextureReferenceIllusion
{
    TextureReferenceIllusion(sf::Texture&);
    sf::Texture & Ref;
};
struct CTextureReferenceIllusion
{
    CTextureReferenceIllusion(const sf::Texture&);
    const sf::Texture & Ref;
};

class GOIEPicture:public Object,public GOIEvirtual
{
    sf::RectangleShape shape;
    sf::Sprite picture;
public:
    GOIEPicture(Position,Position,sf::Color,const sf::Texture&);
    virtual ~GOIEPicture();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
};

class GOIEText:public Object,public GOIEvirtual
{

    sf::RectangleShape shape;
    WrapedText tex;
public:
    GOIEText(Position,Position,sf::Color,std::string);
    virtual ~GOIEText();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
};

class GOIENumber:public Object,public GOIEvirtual
{
    int32_t number;
    sf::RectangleShape shape;
    sf::Text tex;
public:
    GOIENumber(Position,Position,sf::Color);
    virtual ~GOIENumber();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual uint32_t GetTextWidth();
    virtual void SetToDestroy();
    void SetNumber(int32_t);
};

class GOIEPointed:public GOIENumber
{
    uint32_t_pointer * pointer;
public:
    GOIEPointed(Position,Position,sf::Color,uint32_t_pointer*);
    GOIEPointed(Position,GOIENumber,uint32_t_pointer*);
    GOIEPointed(GOIEPointed&);
    virtual ~GOIEPointed();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void SetToDestroy();
};


class GOIEPT:public Object,public GOIEvirtual
{
    GOIEPicture pic;
    GOIEText tex;
public:
    GOIEPT(Position,Position,sf::Color,sf::Texture&,Position,sf::Color,std::string);
    virtual ~GOIEPT();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
};



#endif // GUIOBJECTINFOELEMENT_H
