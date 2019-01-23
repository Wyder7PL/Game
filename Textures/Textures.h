#ifndef TEXTURES_H
#define TEXTURES_H

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include <SFML/Graphics.hpp>

class Textures
{
public:
    static Textures * textures;
    Textures();

    sf::Texture NoTexture;

    sf::Texture Ttavern;
    sf::Texture Tmine;
    sf::Texture Tworkshop;
    sf::Texture Thouse;
    sf::Texture Tmagazine;
    sf::Texture Ttower;
    sf::Texture Tforester;
    sf::Texture Tbarracks;

    sf::Texture Hammer;
    sf::Texture Axe;
    sf::Texture Pickaxe;
    sf::Texture Toolbox;

    sf::Texture Wood;
    sf::Texture Stone;
    sf::Texture Iron;
    sf::Texture Gold;

    sf::Texture Occupants;
    sf::Texture MaxOccupants;

    sf::Texture Sword;
    sf::Texture Spear;
    sf::Texture Bow;
    sf::Texture DoubleShoot;
    sf::Texture HookGun;
    sf::Texture Minigun;
    sf::Texture Uzi;
    sf::Texture Musket;
    sf::Texture SniperRifle;

    sf::Texture WoodenArmor;
    sf::Texture IronPlateArmor;

    sf::Texture Canel;
    sf::Texture HoldOn;
    sf::Texture Allow;
    sf::Texture Enter;
    sf::Texture Exit;

    sf::Texture Ignore;
    sf::Texture DontIgnore;
};

class Tiles
{
public:
    static Tiles * tiles;
    Tiles();
    sf::Texture NoTile;
    sf::Texture Red;
    sf::Texture Blue;
    sf::Texture Yellow;


    sf::Texture GrassTile;
};

#endif // TEXTURES_H
