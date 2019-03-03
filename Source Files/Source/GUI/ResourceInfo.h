#pragma once
#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include "../Anoyher/Object.hpp"
#include "GUIObjects/GOIENumber.h"


class ResourceInfo:public Object
{
    sf::RectangleShape resource;
    sf::Sprite resource2;
    GOIENumber Value;
public:
    ResourceInfo(Position);
    virtual ~ResourceInfo();

    void SetTexture(sf::Texture&);

    void Step();
    void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void SetAmount(int32_t);
};
