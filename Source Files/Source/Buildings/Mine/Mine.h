#pragma once

#include "../Building.h"
#include "../../Textures/Textures.h"
#include "../../Markable/Slot.h"
#include "../../Unit.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "../../Items/ResourceItem.h"

class Mine:public Building
{
    std::list <Slot> worker;
    uint32_t work;

    uint32_t materialtype;
    uint32_t workdemand;

    uint32_t_pointer * BarWork;
    uint32_t_pointer * BarWorkDemand;

    uint32_t emptyreserve;
public:
    Mine(Position,uint32_t);
    virtual ~Mine();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
    virtual void Selected();

    std::list <void*> RDV;
    list_pointer * SlotPointer;
};
