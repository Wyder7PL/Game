#include "PrimaryCTool.h"

PrimaryCTool::PrimaryCTool(uint32_t f)
:ConstructionTool(f)
{
    setMaxWorkPoints(20);
    SetWorkPoints(20);
    SetRange(70);
    image.setTexture(Textures::textures->Hammer);
}
