#include "ToolBox.h"

ToolBox::ToolBox(uint32_t f)
:StorageComponent(f)
{
    Price = 30;
    SetRange(60);
    image.setTexture(Textures::textures->Toolbox);
}

ResourceItem * ToolBox::GetExtractedItem()
{
    ResourceItem * temp = res;
    res = NULL;
    return temp;
}
