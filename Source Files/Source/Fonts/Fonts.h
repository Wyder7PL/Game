#pragma once
#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Fonts
{
public:
    static sf::Font baloo;
    static sf::Font SMB;
    static void loadFonts();

};
