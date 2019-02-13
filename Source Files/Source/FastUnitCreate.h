#pragma once

#include "GUI\GUI.h"
#include "Races/TestRace.h"
//#include "..\CustomGUIObjects\Menu.h"
#include "Tasks\Offense1Task.h"

#include "Items/Tools/PrimaryCTool.h"
#include "Items/Tools/MiningTool.h"
#include "Items/Tools/GatherTool.h"
#include "Items/Tools/ToolBox.h"

#include "Items/Weapions/Spear.h"
#include "Items/Weapions/Sword.h"
#include "Items/Weapions/HookGun.h"
#include "Items/Weapions/Bow.h"
#include "Items/Weapions/Musket.h"
#include "Items/Weapions/MiniGun.h"

#include "Items/Armors/IronPlateArmor.h"
#include "Items/Armors/WoodenArmor.h"

#include "Skills/Building1.h"
#include "Skills/Mining1.h"
#include "Skills/Working1.h"
#include "Skills/Gathering1.h"
#include "Skills/CloseCombat1.h"
#include "Skills/CloseCombat2.h"
#include "Skills/Shooting1.h"

class FastUnitCreate
{
public:
    TestRace * WoodSpearI(Position,uint32_t,bool);
    TestRace * BowI(Position,uint32_t,bool);
    TestRace * MusketI(Position,uint32_t,bool);
    TestRace * WoodSwordII(Position,uint32_t,bool);
    TestRace * IronSwordII(Position,uint32_t,bool);
    TestRace * IronSwordHookII(Position,uint32_t,bool);
    TestRace * IronMinigunI(Position,uint32_t,bool);
    void CreateWithSimpleOffensiveTask(mainControler&,Unit*,Position);
    Offense1Task * GenerateSimpleOffensiveTask(mainControler&,Unit*,Position);
};
