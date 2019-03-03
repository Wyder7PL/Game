#include "MiningTool.h"

MiningTool::MiningTool(uint32_t f)
:StorageComponent(f)
{
    Price = 10;
    SetRange(70);
    image.setTexture(Textures::textures->Pickaxe);
}
