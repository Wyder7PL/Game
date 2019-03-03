#pragma once

#include "OIPicture.h"
#include "OIText.h"
#include "GOIEPT.h"

class OIPT:public ObjectInfo
{
    OIPicture pic;
    OIText tex;
public:
    OIPT(Position,sf::Color,sf::Texture&,Position,sf::Color,std::string);
    virtual GUIObjectInfoElement * Create(Position);

    OIPicture GetPic();
    OIText GetTex();
};
