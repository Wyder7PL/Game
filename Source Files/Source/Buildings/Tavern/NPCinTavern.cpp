#include "NPCinTavern.h"

NPCinTavern::NPCinTavern(Position pos,uint32_t fr)
:fraction(fr),AlredyGone(false),price(0),timeleft(500+rand()%1000)
{
    unit = new TestRace(pos,fr,false);
    price += rand()%1+1;

    uint32_t w = rand()%66;
    if(w<10)
        TESTBuilder();
    else if(w<20)
        TESTMiner();
    else if(w<30)
        TESTGatcherer();
    else if(w<40)
        TESTWorker();
    else if(w<50)
        TESTSpearman();
    else if(w<60)
        TESTBowman();
    else if(w<65)
        TESTMusketMan();
    else
        TESTMinigunner();

}
NPCinTavern::~NPCinTavern()
{
    if(!AlredyGone)
        delete unit;
}
void NPCinTavern::ClearSlot()
{
    AlredyGone = true;
}
Item * NPCinTavern::GIAS(Item * i)
{
    CTextureReferenceIllusion tric(*i->GetImage().getTexture());
    ItemList.push_back(tric);
    return i;
}
Armor * NPCinTavern::GAAS(Armor * a)
{
    CTextureReferenceIllusion tric(*a->GetImage().getTexture());
    ItemList.push_back(tric);
    return a;
}
void NPCinTavern::TESTBuilder()
{
    unit->GiveItem(GIAS(new PrimaryCTool(fraction)));
    unit->SetSkill(new Building1());
    SkillList.push_back("Building1");
    price += rand()%3+2;
}
void NPCinTavern::TESTMiner()
{
    unit->GiveItem(GIAS(new MiningTool(fraction)));
    unit->SetSkill(new Mining1());
    SkillList.push_back("Mining1");
    price += rand()%2+3;
}
void NPCinTavern::TESTGatcherer()
{
    unit->GiveItem(GIAS(new GatherTool(fraction)));
    unit->SetSkill(new Gathering1());
    SkillList.push_back("Gathering1");
    price += rand()%2+3;
}
void NPCinTavern::TESTWorker()
{
    unit->GiveItem(GIAS(new ToolBox(fraction)));
    unit->SetSkill(new Working1());
    SkillList.push_back("Working1");
    price += rand()%1+5;
}
void NPCinTavern::TESTSpearman()
{
    unit->GiveItem(GIAS(new Spear(fraction)));
    if(rand()%8==0){
        unit->WearArmor(GAAS(new IronPlateArmor(fraction)));
        price += rand()%7+3;
    }

    else if(rand()%3==0){
        unit->WearArmor(GAAS(new WoodenArmor(fraction)));
        price += rand()%3+3;
    }
    unit->SetSkill(new CloseCombat1());
    SkillList.push_back("CloseCombat1");
    price += rand()%4+4;
}
void NPCinTavern::TESTBowman()
{
    unit->GiveItem(GIAS(new Bow(fraction)));
    unit->SetSkill(new Shooting1());
    if(rand()%5==0)
    {
        unit->WearArmor(GAAS(new WoodenArmor(fraction)));
        price += rand()%2+4;
    }

    SkillList.push_back("Shooting1");
    price += rand()%4+4;
}
void NPCinTavern::TESTMusketMan()
{
    unit->GiveItem(GIAS(new Musket(fraction)));
    unit->SetSkill(new Shooting1());
    if(rand()%3>0)
    {
        unit->WearArmor(GAAS(new WoodenArmor(fraction)));
        price += rand()%2+4;
    }
    SkillList.push_back("Shooting1");
    price += rand()%7+4;
}
void NPCinTavern::TESTMinigunner()
{
    unit->GiveItem(GIAS(new MiniGun(fraction)));
    unit->WearArmor(GAAS(new IronPlateArmor(fraction)));
    unit->SetSkill(new Shooting1());
    SkillList.push_back("Shooting1");
    price += rand()%10+20;
}

