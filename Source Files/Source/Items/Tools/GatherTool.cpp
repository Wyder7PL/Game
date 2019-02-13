#include "GatherTool.h"

GatherTool::GatherTool(uint32_t f)
:StorageComponent(f)
{
    Price = 10;
    SetRange(70);
    image.setTexture(Textures::textures->Axe);
}
uint32_t GatherTool::Gather(Position pos,Position target,uint32_t id)
{
    if(pos.distance(target) < GetRange())
    {
        if(Charge == Price)
        {
            gathertoll * t = new gathertoll(target,fractions,id);
            AddObject add;
            add.Add(t);
            Charge = 0;
            return 2;
        }
        Charge++;
        return 1;
    }
    return 0;
}
