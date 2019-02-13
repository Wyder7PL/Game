#include "Textures.h"

Textures * Textures::textures = NULL;

Textures::Textures()
{
    if(!NoTexture.loadFromFile("../../Graphic/NoTexture.png")){}

    if(!Ttavern.loadFromFile("../../Graphic/Tavern.png")){}
    if(!Tmine.loadFromFile("../../Graphic/Mine.png")){}
    if(!Tworkshop.loadFromFile("../../Graphic/Workshop.png")){}
    if(!Thouse.loadFromFile("../../Graphic/House.png")){}
    if(!Tmagazine.loadFromFile("../../Graphic/Magazine.png")){}
    if(!Ttower.loadFromFile("../../Graphic/Tower.png")){}
    if(!Tforester.loadFromFile("../../Graphic/Forester.png")){}
    if(!Tbarracks.loadFromFile("../../Graphic/Barracks.png")){}

    if(!Hammer.loadFromFile("../../Graphic/Hammer.png")){}
    if(!Axe.loadFromFile("../../Graphic/Axe.png")){}
    if(!Pickaxe.loadFromFile("../../Graphic/Pickaxe.png")){}
    if(!Toolbox.loadFromFile("../../Graphic/Toolbox.png")){}

    if(!Wood.loadFromFile("../../Graphic/Wood.png")){}
    if(!Stone.loadFromFile("../../Graphic/Stone.png")){}
    if(!Iron.loadFromFile("../../Graphic/Iron.png")){}
    if(!Gold.loadFromFile("../../Graphic/Gold.png")){}

    if(!Occupants.loadFromFile("../../Graphic/Occupants.png")){}
    if(!MaxOccupants.loadFromFile("../../Graphic/MaxOccupants.png")){}

    if(!Sword.loadFromFile("../../Graphic/Sword.png")){}
    if(!Spear.loadFromFile("../../Graphic/Spear.png")){}
    if(!Bow.loadFromFile("../../Graphic/Bow.png")){}
    if(!DoubleShoot.loadFromFile("../../Graphic/DoubleShotgun.png")){}
    if(!HookGun.loadFromFile("../../Graphic/hookgun.png")){}
    if(!Minigun.loadFromFile("../../Graphic/Minigun.png")){}
    if(!Uzi.loadFromFile("../../Graphic/Uzi.png")){}
    if(!Musket.loadFromFile("../../Graphic/Musket.png")){}
    if(!SniperRifle.loadFromFile("../../Graphic/SniperRifle.png")){}


    if(!WoodenArmor.loadFromFile("../../Graphic/WoodenArmor.png")){}
    if(!IronPlateArmor.loadFromFile("../../Graphic/IronPlateArmor.png")){}

    if(!Canel.loadFromFile("../../Graphic/Canel.png")){}
    if(!HoldOn.loadFromFile("../../Graphic/HoldOn.png")){}
    if(!Allow.loadFromFile("../../Graphic/Allow.png")){}
    if(!Enter.loadFromFile("../../Graphic/Enter.png")){}
    if(!Exit.loadFromFile("../../Graphic/Exit.png")){}

    if(!Ignore.loadFromFile("../../Graphic/IgnoreEnemy.png")){}
    if(!DontIgnore.loadFromFile("../../Graphic/DontIgnoreEnemy.png")){}

}
