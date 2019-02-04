#ifndef FONTS_H
#define FONTS_H

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Fonts
{
public:
    static sf::Font baloo;
    static sf::Font SMB;
    static void loadFonts();

};




#endif // FONTS_H
