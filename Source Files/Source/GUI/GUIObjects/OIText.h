#pragma once

#include "ObjectInfo.h"
#include "GOIEText.h"

class OIText:public ObjectInfo
{
    Position wAh;
    sf::Color col;
    std::string str;
public:
    OIText(Position,sf::Color,std::string);
    virtual GUIObjectInfoElement * Create(Position);

    Position GetWah();
    sf::Color GetCol();
    std::string GetStr();
};
