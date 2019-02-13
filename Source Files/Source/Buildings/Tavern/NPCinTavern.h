#pragma once

#include "../../Races/TestRace.h"
#include "../../Items/Tools/PrimaryCTool.h"
#include "../../Items/Tools/MiningTool.h"
#include "../../Items/Tools/GatherTool.h"
#include "../../Items/Tools/ToolBox.h"

#include "../../Items/Weapions/Spear.h"
#include "../../Items/Weapions/Bow.h"
#include "../../Items/Weapions/Musket.h"
#include "../../Items/Weapions/MiniGun.h"

#include "../../Items/Armors/IronPlateArmor.h"
#include "../../Items/Armors/WoodenArmor.h"

#include "../../Skills/Building1.h"
#include "../../Skills/Mining1.h"
#include "../../Skills/Working1.h"
#include "../../Skills/Gathering1.h"
#include "../../Skills/CloseCombat1.h"
#include "../../Skills/Shooting1.h"

#include "../../Races/TestRace.h"

#include "../../Gui/GuiObjects/CTextureReferenceIllusion.h"

class NPCinTavern
{
    uint32_t fraction;
    bool AlredyGone;
public:
    NPCinTavern(Position,uint32_t);
    ~NPCinTavern();
    Unit * unit;
    uint32_t price;
    uint32_t timeleft;
    std::list <std::string> SkillList;
    std::list <CTextureReferenceIllusion> ItemList;
    void ClearSlot();
private:
    Item * GIAS(Item*);///GiveItemAndSometching
    Armor * GAAS(Armor*);///GiveArmorAndSometching
    void TESTBuilder();
    void TESTMiner();
    void TESTGatcherer();
    void TESTWorker();
    void TESTSpearman();
    void TESTBowman();
    void TESTMusketMan();
    void TESTMinigunner();
};
