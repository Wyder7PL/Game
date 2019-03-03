#include "TextureTiles.h"

TextureTiles * TextureTiles::tiles = NULL;

TextureTiles::TextureTiles()
{
    if(!NoTile.loadFromFile("Graphic/Tiles.png",sf::IntRect(0,0,20,20))){}
    if(!Red.loadFromFile("Graphic/Tiles.png",sf::IntRect(20,0,20,20))){}
    if(!Blue.loadFromFile("Graphic/Tiles.png",sf::IntRect(40,0,20,20))){}
    if(!Yellow.loadFromFile("Graphic/Tiles.png",sf::IntRect(60,0,20,20))){}
    if(!GrassTile.loadFromFile("Graphic/Tiles.png",sf::IntRect(0,20,20,20))){}
}
