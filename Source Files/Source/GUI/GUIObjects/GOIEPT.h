#pragma once
#include "GOIEText.h"
#include "GOIEPicture.h"

class GOIEPT:public Object,public GUIObjectInfoElement
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

