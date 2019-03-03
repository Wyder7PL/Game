#pragma once

#include "ObjectInfo.h"
#include "GOIEPicture.h"


class OIPicture:public ObjectInfo
{
    Position wAh;
    sf::Color col;
    sf::Texture & tex;
public:
    OIPicture(Position,sf::Color,sf::Texture&);
    virtual GUIObjectInfoElement * Create(Position);

    Position GetWah();
    sf::Color GetCol();
    sf::Texture & GetTexture();
};
