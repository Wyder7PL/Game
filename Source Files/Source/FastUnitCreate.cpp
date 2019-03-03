#include "FastUnitCreate.h"

TestRace * FastUnitCreate::WoodSpearI(Position pos,uint32_t f,bool fort)
{
    TestRace * u = new TestRace(pos,f);
    u->SetRightItem(new Spear(f));
    u->WearArmor(new WoodenArmor(f));
    u->SetSkill(new CloseCombat1());
    if(fort)
        u->EnterNeartestFortification();
    return u;
}
TestRace * FastUnitCreate::BowI(Position pos,uint32_t f,bool fort)
{
    TestRace * u = new TestRace(pos,f);
    u->SetRightItem(new Bow(f));
    u->SetSkill(new Shooting1());
    if(fort)
        u->EnterNeartestFortification();
    return u;
}
TestRace * FastUnitCreate::MusketI(Position pos,uint32_t f,bool fort)
{
    TestRace * u = new TestRace(pos,f);
    u->SetRightItem(new Musket(f));
    u->SetSkill(new Shooting1());
    if(fort)
        u->EnterNeartestFortification();
    return u;
}

TestRace * FastUnitCreate::IronSwordII(Position pos,uint32_t f,bool fort)
{
    TestRace * u = new TestRace(pos,f);
    u->WearArmor(new IronPlateArmor(f));
    u->SetRightItem(new Sword(f));
    u->SetSkill(new CloseCombat2());
    if(fort)
        u->EnterNeartestFortification();
    return u;
}
TestRace * FastUnitCreate::IronSwordHookII(Position pos,uint32_t f,bool fort)
{
    TestRace * u = new TestRace(pos,f);
    u->WearArmor(new IronPlateArmor(f));
    u->SetRightItem(new Sword(f));
    u->SetLeftItem(new HookGun(f));
    u->SetSkill(new CloseCombat2());
    if(fort)
        u->EnterNeartestFortification();
    return u;
}
TestRace * FastUnitCreate::WoodSwordII(Position pos,uint32_t f,bool fort)
{
    TestRace * u = new TestRace(pos,f);
    u->WearArmor(new WoodenArmor(f));
    u->SetRightItem(new Sword(f));
    u->SetSkill(new CloseCombat2());
    if(fort)
        u->EnterNeartestFortification();
    return u;
}
TestRace * FastUnitCreate::IronMinigunI(Position pos,uint32_t f,bool fort)
{
    TestRace * u = new TestRace(pos,f);
    u->WearArmor(new IronPlateArmor(f));
    u->SetRightItem(new MiniGun(f));
    u->SetSkill(new Shooting1());
    if(fort)
        u->EnterNeartestFortification();
    return u;
}
void FastUnitCreate::CreateWithSimpleOffensiveTask(mainControler & mac,Unit* u,Position pos)
{
    mac.CreateObject(u);
    std::list <Position> posi;
    posi.push_back(pos);
    Offense1Task * oft = new Offense1Task(u->GetID(),posi);
    mac.CreateEffect(oft);
}
Offense1Task * FastUnitCreate::GenerateSimpleOffensiveTask(mainControler & mac,Unit* u,Position pos)
{
    std::list <Position> posi;
    posi.push_back(pos);
    Offense1Task * oft = new Offense1Task(u->GetID(),posi);
    return oft;
}

/// ////////////////////////////////////////////////////////////////////////////////// ///
/// ////////////////////////////////////////////////////////////////////////////////// ///
/// ////////////////////////////////////////////////////////////////////////////////// ///
