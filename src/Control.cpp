#include "../include/Control.h"

DebugNavigationPoint::DebugNavigationPoint(Position pos)
:Object(pos)
{
    physicshape = new Circle(1);
    mask = 0;
    SetZIndex(11);

    PhysicObject::SetPosition(pos.GetX(),pos.GetY());

    temp.setPosition(position.GetX(),position.GetY());
    temp.setOrigin(20,20);
    temp.setRadius(20);
    temp.setFillColor(sf::Color(100,100,100,100));
}

void DebugNavigationPoint::Step()
{
    temp.setPosition(sfLocalPos(position));
}
void DebugNavigationPoint::draw(sf::RenderTarget & target,sf::RenderStates states) const
{target.draw(temp,states);}

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

Control::Control()
:InMenu(true)
{
    menu = new Menu;
    AddObject add;
    add.Add(menu);

    MainMap = NULL;
    Textures::textures = new Textures();
    Tiles::tiles = new Tiles();
}

Control::~Control()
{
    mac.DestroyElements();
    ReS.DestroyElements();
    for(std::list <SafePointer*>::iterator ite = SafePointer::Pointers.begin();ite != SafePointer::Pointers.end();)
    {
        delete (*ite);
        ite = SafePointer::Pointers.erase(ite);
    }
    if(MainMap!=NULL)
        delete MainMap;
    for(std::vector <Fraction*>::iterator ite = fra.begin();ite != fra.end();)
    {
        delete (*ite);
        ite = fra.erase(ite);
    }
    delete [] Recipe::Recipes;
    delete Textures::textures;
    delete Tiles::tiles;
}

void Control::TESTCREATE()
{
    ReS.DefaultResourceListCreator();
    ReS.SetActive();

    MainMap = new Map(50,70);///42+9,38+8///1024,768
    MainMap->TEST_LoadMap();

    Map::ActualMap = MainMap;

    ground = new Ground();
    ground->SetDimensions(uint32X2(20,20));
    ground->SetMapTiles(MainMap->GetTiles(),uint32X2(MainMap->GetWidth(),MainMap->GetHeight()));
    mac.CreateObject(ground);

    TESTCREATEFRACTIONS();

    fra[2]->GetEco()->GEE(1)->SetAmount(40);
    fra[2]->GetEco()->GEE(2)->SetAmount(10);
    fra[2]->GetEco()->GEE(4)->SetAmount(20);


    mac.CreateObject(new EndOnNoFractionObjects(false,2));

    CommonTree * ct;
    for(uint32_t i = 0;i<5;i++)
    {
        ct = new CommonTree(Position(rand()%800+200,rand()%700+100));
        mac.CreateObject(ct);
    }

    TestRace * u = new TestRace(Position(600,350),2);
    u->SetRightItem(new GatherTool(2));
    u->SetSkill(new Gathering1());
    mac.CreateObject(u);

    u = new TestRace(Position(600,300),2);
    u->SetRightItem(new PrimaryCTool(2));
    u->SetSkill(new Building1());
    mac.CreateObject(u);

    {
        std::list <BarrackUnitStorage> BUS;
        std::list <UnitTask*> uit;

        {
        u = new TestRace(Position(0,0),3);
        u->WearArmor(new WoodenArmor(3));
        u->SetRightItem(new Spear(3));
        u->SetSkill(new CloseCombat1());
        std::list <Position> pos;pos.push_back(Position(600,800));pos.push_back(Position(500,300));
        Offense1Task * oft = new Offense1Task(u->GetID(),pos);
        uit.push_back(oft);
        BarrackUnitStorage bus(u,uit,300);
        BUS.push_back(bus);
        uit.clear();
        }
        {
        u = new TestRace(Position(0,0),3);
        u->WearArmor(new WoodenArmor(3));
        u->SetRightItem(new Musket(3));
        u->SetSkill(new Shooting1());
        std::list <Position> pos;pos.push_back(Position(800,1000));pos.push_back(Position(250,900));
        pos.push_back(Position(800,800));pos.push_back(Position(250,700));
        pos.push_back(Position(800,600));pos.push_back(Position(250,500));
        Offense1Task * oft = new Offense1Task(u->GetID(),pos);
        uit.push_back(oft);
        BarrackUnitStorage bus(u,uit,3000);
        BUS.push_back(bus);
        uit.clear();
        }
        {
        u = new TestRace(Position(0,0),3);
        u->WearArmor(new IronPlateArmor(3));
        u->SetRightItem(new MiniGun(3));
        u->SetSkill(new Shooting1());
        std::list <Position> pos;pos.push_back(Position(800,1000));pos.push_back(Position(250,900));
        pos.push_back(Position(200,800));pos.push_back(Position(200,300));
        Offense1Task * oft = new Offense1Task(u->GetID(),pos);
        uit.push_back(oft);
        BarrackUnitStorage bus(u,uit,30000);
        BUS.push_back(bus);
        uit.clear();
        }
        {
        u = new TestRace(Position(0,0),3);
        u->SetRightItem(new SniperRifle(3));
        u->SetSkill(new Shooting1());
        std::list <Position> pos;pos.push_back(Position(800,1000));
        Offense1Task * oft = new Offense1Task(u->GetID(),pos);
        uit.push_back(oft);
        BarrackUnitStorage bus(u,uit,100000);
        BUS.push_back(bus);
        uit.clear();
        }

        OnBarracksDestroy * b = new OnBarracksDestroy(Position(800,65*20),3,BUS,true);
        mac.CreateObject(b);
    }

    Tower * t;
    for(uint32_t i = 0;i<12;i++)
    {
        if(i>10)
        {
        u = new TestRace(Position(640-i*20,340-i*20),2);
        u->WearArmor(new IronPlateArmor(2));
        u->SetRightItem(new Sword(2));
        u->SetSkill(new CloseCombat2());
        mac.CreateObject(u);
        }
        if(i>9)
        {
            t = new Tower(Position(650+(i-10)*250,60*20),3);
            mac.CreateObject(t);
            u = new TestRace(Position(700+(i-10)*250,62*20),3);
            u->SetRightItem(new Musket(3));
            u->SetSkill(new Shooting1());
            u->EnterNeartestFortification();
            mac.CreateObject(u);
            u = new TestRace(Position(680+(i-10)*250,62*20),3);
            u->SetRightItem(new Bow(3));
            u->SetSkill(new Shooting1());
            u->EnterNeartestFortification();
            mac.CreateObject(u);
        }

        u = new TestRace(Position(1000+i*10,1000+i*10),3);
        u->SetRightItem(new Sword(3));
        u->SetLeftItem(new HookGun(3));
        u->SetSkill(new CloseCombat2());
        mac.CreateObject(u);/**/
    }


    MarkUnit::CreateMUS(new MUSGUICreate());

    uint32_t_pointer * poi = new uint32_t_pointer(&Markable::SelectedType);
    GOIEPointed * ppp = new GOIEPointed(Position(10,200),Position(40,20),sf::Color(0,0,0,0),poi);
    mac.CreateObject(ppp);

    gui = new GUI();

    mac.CreateObject(gui);
}

void Control::Offensive()
{
    ReS.DefaultResourceListCreator();
    ReS.SetActive();

    MainMap = new Map(110,40);///42+9,38+8///1024,768
    MainMap->TEST_LoadMap1();

    Map::ActualMap = MainMap;

    ground = new Ground();
    ground->SetDimensions(uint32X2(20,20));
    ground->SetMapTiles(MainMap->GetTiles(),uint32X2(MainMap->GetWidth(),MainMap->GetHeight()));
    mac.CreateObject(ground);

    TESTCREATEFRACTIONS();

    fra[4]->GetEco()->GEE(1)->SetAmount(10);
    fra[4]->GetEco()->GEE(3)->SetAmount(10);

    mac.CreateObject(new EndOnNoFractionObjects(true,4));
    mac.CreateObject(new EndOnNoFractionObjects(false,2));




    TestRace * u;
    u = new TestRace(Position(220,200),2);
    u->SetRightItem(new Shootgun(2));
    u->SetSkill(new Shooting1());
    uint32_t ShootgunID = u->GetID();
    mac.CreateObject(u);
    u = new TestRace(Position(270,200),2);
    u->WearArmor(new IronPlateArmor(2));
    u->SetRightItem(new Sword(2));
    u->SetLeftItem(new HookGun(2));
    u->SetSkill(new CloseCombat2());
    mac.CreateObject(u);
    for(uint32_t i = 0,j = 0;j < 3;i++)
    {
        if(i==3)
            i=0;

            u = new TestRace(Position(220+40*i,50+40*j),2);
            u->SetRightItem(new Spear(2));
            u->WearArmor(new WoodenArmor(2));
            u->SetSkill(new CloseCombat1());
            mac.CreateObject(u);
        if(i < 2)
        {

                u = new TestRace(Position(240+40*i,280+40*j),2);
                u->SetRightItem(new Bow(2));
                u->SetSkill(new Shooting1());
                mac.CreateObject(u);
        }
        if(i==2)
            j++;
    }


    Tower * t = new Tower(Position(1420,580),4);
    mac.CreateObject(t);
    {
        u = new TestRace(Position(1299,500),4);
        u->WearArmor(new WoodenArmor(4));
        u->SetRightItem(new Sword(4));
        u->SetLeftItem(new HookGun(4));
        u->SetSkill(new CloseCombat2());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(1300,500),4);
        u->SetRightItem(new Uzi(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }


    {
        t = new Tower(Position(700,350),4);
        mac.CreateObject(t);
        u = new TestRace(Position(700,350),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(700,350),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }

    {
        t = new Tower(Position(1500,100),4);
        mac.CreateObject(t);
        u = new TestRace(Position(1500,100),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(1500,100),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }

    {
        t = new Tower(Position(800,550),4);
        mac.CreateObject(t);
        u = new TestRace(Position(800,550),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(800,550),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }


    {
        t = new Tower(Position(1000,120),4);
        mac.CreateObject(t);
        u = new TestRace(Position(1000,120),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(1000,120),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }

    {
        t = new Tower(Position(2100,600),4);
        mac.CreateObject(t);
        u = new TestRace(Position(2100,600),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(2100,600),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }
    {
        t = new Tower(Position(2200,100),4);
        mac.CreateObject(t);
        u = new TestRace(Position(2200,100),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(2200,100),4);
        u->SetRightItem(new Musket(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }
    {
        t = new Tower(Position(1850,300),4);
        mac.CreateObject(t);
        u = new TestRace(Position(1850,300),4);
        u->SetRightItem(new Musket(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
        u = new TestRace(Position(1850,300),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        u->EnterNeartestFortification();
        mac.CreateObject(u);
    }

    mac.CreateObject(new Magazine(Position(1000,500),4));
    mac.CreateObject(new Magazine(Position(2100,300),4));
    mac.CreateObject(new Forester(Position(1300,300),4));
    mac.CreateObject(new Tavern(Position(1600,700),4));
    mac.CreateObject(new Tavern(Position(1850,120),4));
    mac.CreateObject(new Mine(Position(1150,600),4));
    mac.CreateObject(new Mine(Position(870,270),4));
    mac.CreateObject(new Workshop(Position(2000,450),4));

    BuildingConstruction * c;
    for(uint32_t i = 0,j = 0;i < 10;i++)
    {
        if(i%5<3)
            mac.CreateObject(new House(Position(1570+90*j,70+110*(i%5)),4));
        else
        {
            c = new HouseConstruction(Position(1570+90*j,70+110*(i%5)),4);
            c->TESTCreateDemand(1,8);
            mac.CreateObject(c);
        }

        if(i == 4)
            j++;
    }

    u = new TestRace(Position(1200,600),4);
    u->SetRightItem(new PrimaryCTool(4));
    u->SetSkill(new Building1());
    mac.CreateObject(u);

    u = new TestRace(Position(1000,350),4);
    u->SetRightItem(new GatherTool(4));
    u->SetSkill(new Gathering1());
    mac.CreateObject(u);

    for(uint32_t i = 0;i<2;i++)
    {
        u = new TestRace(Position(1100-50*i,400),4);
        u->SetRightItem(new MiningTool(4));
        u->SetSkill(new Mining1());
        mac.CreateObject(u);
    }

    u = new TestRace(Position(2300,350),4);
    u->SetRightItem(new ToolBox(4));
    u->SetSkill(new Working1());
    mac.CreateObject(u);

    u = new TestRace(Position(1670,700),4);
    u->WearArmor(new IronPlateArmor(4));
    u->SetRightItem(new Sword(4));
    u->SetLeftItem(new Shootgun(4));
    u->SetSkill(new CloseCombat2());
    mac.CreateObject(u);

    u = new TestRace(Position(1900,100),4);
    u->SetRightItem(new SniperRifle(4));
    u->SetSkill(new Shooting1());
    mac.CreateObject(u);


    for(uint32_t i = 0;i<2;i++)
    {
        u = new TestRace(Position(800+400*i,200+200*i),4);
        u->WearArmor(new WoodenArmor(4));
        u->SetRightItem(new Sword(4));
        u->SetSkill(new CloseCombat2());
        mac.CreateObject(u);
        u = new TestRace(Position(1000+500*i,700-300*i),4);
        u->SetRightItem(new Bow(4));
        u->SetSkill(new Shooting1());
        mac.CreateObject(u);
        for(uint32_t j = 0;j<3;j++)
        {
            u = new TestRace(Position(1200+100*i+100*j,100+500*i),4);
            u->WearArmor(new WoodenArmor(4));
            u->SetRightItem(new Spear(4));
            u->SetSkill(new CloseCombat1());
            mac.CreateObject(u);
        }
        u = new TestRace(Position(1850+i*350,500-i*300),4);
        u->SetRightItem(new Sword(4));
        u->WearArmor(new WoodenArmor(4));
        u->SetSkill(new CloseCombat2());
        mac.CreateObject(u);
    }


    {
        CUOAScanObject * cuoaobj = new CUOAScanObject(Position(1200,400),450);
        std::list <BarrackUnitStorage> BUS;
        std::list <UnitTask*> uit;
        for(uint32_t i = 0;i<2;i++)
        {
            u = new TestRace(Position(1100,i*800),4);
            u->SetRightItem(new Musket(4));
            u->SetSkill(new Shooting1());

            BarrackUnitStorage bus(u,uit,i*10);
            BUS.push_back(bus);
        }
        CreateUnitsOnIDAproach * cuoa = new CreateUnitsOnIDAproach(cuoaobj->GetID(),BUS,ShootgunID);
        mac.CreateObject(cuoaobj);
        mac.CreateEffect(cuoa);
    }
    {
        CUOAScanObject * cuoaobj = new CUOAScanObject(Position(2200,400),500);
        std::list <BarrackUnitStorage> BUS;
        std::list <UnitTask*> uit;
        for(uint32_t i = 0;i<5;i++)
        {
            u = new TestRace(Position(2000+i*15,800),2);
            u->SetRightItem(new Sword(2));
            u->SetSkill(new CloseCombat2());

            BarrackUnitStorage bus(u,uit,i*1);
            BUS.push_back(bus);
        }
        for(uint32_t i = 0;i<3;i++)
        {
            u = new TestRace(Position(2000+i*15,830),2);
            u->SetRightItem(new Musket(2));
            u->SetSkill(new Shooting1());

            BarrackUnitStorage bus(u,uit,4+i*1);
            BUS.push_back(bus);
        }
        CreateUnitsOnFractionAproach * cuoa = new CreateUnitsOnFractionAproach(cuoaobj->GetID(),BUS,2);
        mac.CreateObject(cuoaobj);
        mac.CreateEffect(cuoa);
    }


    u = new TestRace(Position(1800,0),4);
    u->SetRightItem(new Uzi(4));
    u->SetSkill(new Shooting1());
    mac.CreateObject(u);
    std::list <Position> pos;pos.push_back(Position(1600,800));pos.push_back(Position(1400,0));
    pos.push_back(Position(1200,800));pos.push_back(Position(1000,0));pos.push_back(Position(800,800));
    pos.push_back(Position(600,600));
    Offense1Task * oft = new Offense1Task(u->GetID(),pos);
    mac.CreateEffect(oft);

    CommonTree * ct;
    for(uint32_t i = 0;i<10;i++)
    {
        ct = new CommonTree(Position(rand()%2300+200,rand()%600+100));
        mac.CreateObject(ct);
    }

    MarkUnit::CreateMUS(new MUSGUICreate());
    gui = new GUI();

    mac.CreateObject(gui);
}

void Control::Survival()
{
    ReS.DefaultResourceListCreator();
    ReS.SetActive();

    MainMap = new Map(120,120);///150*20=3000
    MainMap->TEST_LoadMap2();

    Map::ActualMap = MainMap;

    ground = new Ground();
    ground->SetDimensions(uint32X2(20,20));
    ground->SetMapTiles(MainMap->GetTiles(),uint32X2(MainMap->GetWidth(),MainMap->GetHeight()));
    mac.CreateObject(ground);

    TESTCREATEFRACTIONS();

    fra[2]->GetEco()->GEE(1)->SetAmount(40);
    fra[2]->GetEco()->GEE(4)->SetAmount(30);
    fra[2]->ChangeMaxResidents(6);

    FastUnitCreate fus;

    float TimeModifier = 2.0;
    mac.CreateObject(new MagazineSurvive(Position(200+60*20,60*20),2,false,(20000*TimeModifier)+5000));
    TestRace * u = new TestRace(Position(1300,1200),2);
    u->SetRightItem(new PrimaryCTool(2));
    u->SetSkill(new Building1());
    mac.CreateObject(u);
    for(uint32_t i = 0;i<6;i++)
    {
        if(i%3==0)
            mac.CreateObject(fus.MusketI(Position(1400+200*cos(0.8+i),1200+200*sin(0.8+i)),2,true));
        mac.CreateObject(fus.BowI(Position(1400+250*cos(1.5*i),1200+250*sin(1.5*i)),2,true));
        mac.CreateObject(new Tower(Position(1400+450*cos(i),1200+450*sin(i)),2));
    }

    auto lambda =[]( mainControler & mmc,Position pos, Unit * u, uint32_t time )->BarrackUnitStorage
    {
        FastUnitCreate lfus;
        Offense1Task * o = lfus.GenerateSimpleOffensiveTask(mmc,u,pos);
        std::list <UnitTask*> unitt;unitt.push_back(o);
        return BarrackUnitStorage(u,unitt,time);
    };

    uint32_t FirstMusket = rand()%8, Mini1 = rand()%4, Mini2 = rand()%4+4;
    std::list <BarrackUnitStorage> BUS;
    std::list <UnitTask*> uit;
    for(uint32_t i = 0,k = 0;i<3;i++)
    {
        for(uint32_t j = 0;j<3;j++)
        {
           if(i!=1||j!=1)
           {
                BUS.push_back(lambda(mac,Position(1400,1200),fus.WoodSpearI(Position(0,0),1,false),(1000+rand()%5000)*TimeModifier));
                BUS.push_back(lambda(mac,Position(1400,1200),fus.BowI(Position(0,0),1,false),(2000+rand()%8000)*TimeModifier));

                if(k==FirstMusket)
                    BUS.push_back(lambda(mac,Position(1400,1200),fus.MusketI(Position(0,0),1,false),(1000+rand()%5000)*TimeModifier));

                uint32_t random;
                for(uint32_t l = 0;l<3;l++)
                {
                    random = 5000*(l+1)*3+rand()%7000;
                    BUS.push_back(lambda(mac,Position(1400,1200),fus.WoodSwordII(Position(0,0),1,false),random*TimeModifier));
                    BUS.push_back(lambda(mac,Position(1400,1200),fus.WoodSwordII(Position(0,0),1,false),(random+10)*TimeModifier));
                    random = 10000+l*5000+rand()%5000;
                    switch(rand()%5)
                    {
                    case 0:{
                        BUS.push_back(lambda(mac,Position(1400,1200),fus.MusketI(Position(0,0),1,false),random*TimeModifier));
                        BUS.push_back(lambda(mac,Position(1400,1200),fus.MusketI(Position(0,0),1,false),(random+30)*TimeModifier));
                        break;}
                    case 1:{
                        for(uint32_t m = 0;m<4;m++)
                            BUS.push_back(lambda(mac,Position(1400,1200),fus.WoodSpearI(Position(0,0),1,false),(random+m*30)*TimeModifier));
                        break;}
                    case 2:{
                        for(uint32_t m = 0;m<2;m++)
                        {
                            BUS.push_back(lambda(mac,Position(1400,1200),fus.WoodSpearI(Position(0,0),1,false),(random+m*30)*TimeModifier));
                            BUS.push_back(lambda(mac,Position(1400,1200),fus.BowI(Position(0,0),1,false),(random+120+m*30)*TimeModifier));
                        }
                        break;}
                    case 3:{
                        for(uint32_t m = 0;m<3;m++)
                            BUS.push_back(lambda(mac,Position(1400,1200),fus.BowI(Position(0,0),1,false),(random+30+m*30)*TimeModifier));
                        BUS.push_back(lambda(mac,Position(1400,1200),fus.WoodSwordII(Position(0,0),1,false),random*TimeModifier));
                        break;}
                    default:{
                        BUS.push_back(lambda(mac,Position(1400,1200),fus.IronSwordHookII(Position(0,0),1,false),random*TimeModifier));
                        break;}
                    }
                }
                if(Mini1==k||Mini2==k)
                    BUS.push_back(lambda(mac,Position(1400,1200),fus.IronMinigunI(Position(0,0),1,false),(20000+k*100)*TimeModifier));



                Barracks * bar = new Barracks(Position(250+i*1000+(rand()%100+50),25+j*1000+rand()%150),1,BUS);
                switch(rand()%3)
                {
                case 0:{
                    mac.CreateObject(fus.MusketI(Position( 250+i*1000+(rand()%100+50), 25+j*1000+rand()%150 ),1,false));
                    break;}
                case 1:{
                    mac.CreateObject(fus.BowI(Position( 250+i*1000+(rand()%100+50), 25+j*1000+rand()%150 ),1,false));
                    mac.CreateObject(fus.WoodSpearI(Position( 250+i*1000+(rand()%100+50), 25+j*1000+rand()%150 ),1,false));
                    break;}
                default:{
                    mac.CreateObject(fus.WoodSwordII(Position( 250+i*1000+(rand()%100+50), 25+j*1000+rand()%150 ),1,false));
                    mac.CreateObject(fus.WoodSpearI(Position( 250+i*1000+(rand()%100+50), 25+j*1000+rand()%150 ),1,false));
                    break;}
                }

                mac.CreateObject(bar);
                BUS.clear();
                k++;
           }
        }
    }

    CommonTree * ct;
    for(uint32_t i = 0;i<20;i++)
    {
        ct = new CommonTree(Position(rand()%2300+200,rand()%2300+200));
        mac.CreateObject(ct);
    }

    MarkUnit::CreateMUS(new MUSGUICreate());
    gui = new GUI();

    mac.CreateObject(gui);
}

void Control::TESTCREATEFRACTIONS()
{
    Fraction::Fractions = &fra;
    Fraction * f;
    for(uint32_t i = 0;i < 8;i++)
    {
        f = new Fraction(i);
        if(i==1)
            f->SetFractionColor(sf::Color(180,0,0));
        if(i==2)
            f->SetFractionColor(sf::Color(100,100,255));
        if(i==3)
            f->SetFractionColor(sf::Color(0,180,0));
        if(i==4)
            f->SetFractionColor(sf::Color(180,180,0));
        fra.push_back(f);
    }
}

void Control::AddObjects()
{
    for(std::list <Object*>::iterator ite = AddObject::objects.begin();ite != AddObject::objects.end();ite++)
        mac.CreateObject((*ite));
    AddObject::objects.clear();
    for(std::list <EffectObject*>::iterator ite = AddObject::effects.begin();ite != AddObject::effects.end();ite++)
        mac.CreateEffect((*ite));
    AddObject::effects.clear();
}

void Control::RefreshPointers()
{
    for(std::list <SafePointer*>::iterator ite = SafePointer::Pointers.begin();ite != SafePointer::Pointers.end();)
    {
        if((*ite)->StepnWait())
        {
            delete (*ite);
            ite = SafePointer::Pointers.erase(ite);
        }
        else
            ite++;
    }
}

void Control::MoveScreen()
{
    Position pos = ground->GetPosition();
    bool moved = false;
    if(Keyboard::MouseX() < 10 && pos.GetX()>175)
    {
        GraphicControler::viewinfo.MoveView(-10,0);
        moved = true;
    }
    else if(Keyboard::MouseX() > 1014 && pos.GetX()-160+44*20 < MainMap->GetWidth()*20)
    {
        GraphicControler::viewinfo.MoveView(10,0);
        moved = true;
    }
    if(Keyboard::MouseY() < 10 && pos.GetY()>0)
    {
        GraphicControler::viewinfo.MoveView(0,-10);
        moved = true;
    }
    else if(Keyboard::MouseY() > 758 && pos.GetY()+40*20 < MainMap->GetHeight()*20)
    {
        GraphicControler::viewinfo.MoveView(0,10);
        moved = true;
    }
    if(moved)
        ground->SetMapTiles(MainMap->GetTiles(),uint32X2(MainMap->GetWidth(),MainMap->GetHeight()));
}

void Control::DeleteMenu()
{
    menu->SetToDestroy();
    menu = NULL;
    InMenu = false;
}

void Control::Step()
{

    if(InMenu)
    {
        switch(menu->Get())
        {
        case 0: {break;}
        case 1:
            {
                TESTCREATE();
                DeleteMenu();
                break;
            }
        case 2:
            {
                Offensive();
                DeleteMenu();
                break;
            }
        case 3:
            {
                Survival();
                DeleteMenu();
                break;
            }
        }
    }
    else
    {
        MoveScreen();
        gui->Refresh();
    }
    Markable::RestartSelectedType();
    RefreshPointers();
    mac.Step();

    AddObjects();
}
