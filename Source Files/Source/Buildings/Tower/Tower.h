#pragma once

#include "../Building.h"
#include "../../Textures/Textures.h"
#include "../../Pointers/void_pointer.h"
#include "../../Unit.h"
#include "../../Items/Weapions/SingleShot.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "../../GUI/GUIObjects/CTextureReferenceIllusion.h"
#include "../../GUI/GUIObjects/MultiButtons/OISlotElementsStorage.h"

struct BoolPointer
{
    BoolPointer();
    ~BoolPointer();
    void_pointer * point;
    bool variable;
};

class Tower:public Building,public Creature
{
    std::list <Slot> shooter;
    uint32_t work;

    BoolPointer State[2];
    BoolPointer Disable[2];
public:
    Tower(Position,uint32_t);
    Tower(Position,uint32_t,Unit*,Unit*);
    virtual ~Tower();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
    virtual void Selected();

    std::list <void*> RDV;
    list_pointer * SlotPointer;
protected:
    virtual bool TypeComparation(std::list <Info>::iterator);
private:
    void Kick(std::list<Slot>::iterator&);
};
