#include "Textures.h"

Textures * Textures::textures = NULL;

Textures::Textures()
{
    if(!NoTexture.loadFromFile("TempGraphics/NoTexture.png")){}

    if(!Ttavern.loadFromFile("TempGraphics/Tavern.png")){}
    if(!Tmine.loadFromFile("TempGraphics/Mine.png")){}
    if(!Tworkshop.loadFromFile("TempGraphics/Workshop.png")){}
    if(!Thouse.loadFromFile("TempGraphics/House.png")){}
    if(!Tmagazine.loadFromFile("TempGraphics/Magazine.png")){}
    if(!Ttower.loadFromFile("TempGraphics/Tower.png")){}
    if(!Tforester.loadFromFile("TempGraphics/Forester.png")){}
    if(!Tbarracks.loadFromFile("TempGraphics/Barracks.png")){}

    if(!Hammer.loadFromFile("TempGraphics/Hammer.png")){}
    if(!Axe.loadFromFile("TempGraphics/Axe.png")){}
    if(!Pickaxe.loadFromFile("TempGraphics/Pickaxe.png")){}
    if(!Toolbox.loadFromFile("TempGraphics/Toolbox.png")){}

    if(!Wood.loadFromFile("TempGraphics/Wood.png")){}
    if(!Stone.loadFromFile("TempGraphics/Stone.png")){}
    if(!Iron.loadFromFile("TempGraphics/Iron.png")){}
    if(!Gold.loadFromFile("TempGraphics/Gold.png")){}

    if(!Occupants.loadFromFile("TempGraphics/Occupants.png")){}
    if(!MaxOccupants.loadFromFile("TempGraphics/MaxOccupants.png")){}

    if(!Sword.loadFromFile("TempGraphics/Sword.png")){}
    if(!Spear.loadFromFile("TempGraphics/Spear.png")){}
    if(!Bow.loadFromFile("TempGraphics/Bow.png")){}
    if(!DoubleShoot.loadFromFile("TempGraphics/DoubleShotgun.png")){}
    if(!HookGun.loadFromFile("TempGraphics/hookgun.png")){}
    if(!Minigun.loadFromFile("TempGraphics/Minigun.png")){}
    if(!Uzi.loadFromFile("TempGraphics/Uzi.png")){}
    if(!Musket.loadFromFile("TempGraphics/Musket.png")){}
    if(!SniperRifle.loadFromFile("TempGraphics/SniperRifle.png")){}


    if(!WoodenArmor.loadFromFile("TempGraphics/WoodenArmor.png")){}
    if(!IronPlateArmor.loadFromFile("TempGraphics/IronPlateArmor.png")){}

    if(!Canel.loadFromFile("TempGraphics/Canel.png")){}
    if(!HoldOn.loadFromFile("TempGraphics/HoldOn.png")){}
    if(!Allow.loadFromFile("TempGraphics/Allow.png")){}
    if(!Enter.loadFromFile("TempGraphics/Enter.png")){}
    if(!Exit.loadFromFile("TempGraphics/Exit.png")){}

    if(!Ignore.loadFromFile("TempGraphics/IgnoreEnemy.png")){}
    if(!DontIgnore.loadFromFile("TempGraphics/DontIgnoreEnemy.png")){}

}

Tiles * Tiles::tiles = NULL;

Tiles::Tiles()
{
    if(!NoTile.loadFromFile("TempGraphics/Tiles.png",sf::IntRect(0,0,20,20))){}
    if(!Red.loadFromFile("TempGraphics/Tiles.png",sf::IntRect(20,0,20,20))){}
    if(!Blue.loadFromFile("TempGraphics/Tiles.png",sf::IntRect(40,0,20,20))){}
    if(!Yellow.loadFromFile("TempGraphics/Tiles.png",sf::IntRect(60,0,20,20))){}
    if(!GrassTile.loadFromFile("TempGraphics/Tiles.png",sf::IntRect(0,20,20,20))){}
}
