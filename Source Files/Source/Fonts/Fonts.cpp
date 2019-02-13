#include "Fonts.h"

sf::Font Fonts::baloo;

sf::Font Fonts::SMB;

void Fonts::loadFonts()
{
    if(!Fonts::baloo.loadFromFile("../../Fonts/baloo.ttf")){}
    if(!Fonts::SMB.loadFromFile("../../Fonts/SMB.ttf")){}
}
