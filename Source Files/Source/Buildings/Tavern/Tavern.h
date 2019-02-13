#pragma once

#include "../../Races/TestRace.h"
#include "../Building.h"
#include "../../Textures/Textures.h"
#include "../../GUI/GUIObjects/OIPT.h"
#include "../../GUI/GUIObjects/GOIEPTHorisontal.h"
#include "../../GUI/GUIObjects/MultiButtons/OIMBSelectOne.h"
#include "../../GUI/GUIObjects/MultiButtons/OIDropDown.h"

#include "GOIEPushareButton.h"
#include "NPCinTavern.h"

class Tavern:public Building
{
    std::vector <NPCinTavern*> InTavern;
    uint32_t GUIButton;
    uint32_t perviousbutton;
    bool change;
    uint32_t_pointer * GUIButtonPoint;
    std::list <GUIObjectInfoElement*> GUIList;
    void_pointer * guiinfo;

    bool ButtonState;
    void_pointer * ButtonStatePoint;
    bool ButtonDisable;
    void_pointer * ButtonDisablePoint;

public:
    Tavern(Position,uint32_t);
    virtual ~Tavern();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
    virtual void Selected();

private:
    void ChangeGuiInfo();
};
