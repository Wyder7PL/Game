#pragma once

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include <SFML/Graphics.hpp>

class TextureTiles
{
public:
    static TextureTiles * tiles;
    TextureTiles();
    sf::Texture NoTile;
    sf::Texture Red;
    sf::Texture Blue;
    sf::Texture Yellow;


    sf::Texture GrassTile;
};
