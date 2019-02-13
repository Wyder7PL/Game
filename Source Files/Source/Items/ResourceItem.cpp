#include "ResourceItem.h"

ResourceItem::ResourceItem(uint32_t f,uint32_t t):Item(f),type(t)
{
    amount = 1;maxamount = 1;
    switch(type)
    {
        case 1:{image.setTexture(Textures::textures->Wood);break;}
        case 2:{image.setTexture(Textures::textures->Stone);break;}
        case 3:{image.setTexture(Textures::textures->Iron);break;}
        case 4:{image.setTexture(Textures::textures->Gold);break;}
        default:{break;}
    }
}
uint32_t ResourceItem::GetType(){return type;}

