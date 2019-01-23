#include "Tavern.h"

GOIEPushareButton::GOIEPushareButton(Position pos,Position dim,sf::Color col,void_pointer*st,void_pointer*dis)
:Object(pos),number(pos,Position(50,dim.GetY()),col)
,button(Position(pos.GetX()+60,pos.GetY()),Position(50,dim.GetY()),st,dis)
{

}
void GOIEPushareButton::Step()
{
    number.Step();
    button.Step();
}
void GOIEPushareButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    number.draw(target,states);
    button.draw(target,states);
}
void GOIEPushareButton::ChangePosition(Position pos)
{
    position = pos;
    number.ChangePosition(pos);
    button.ChangePosition(Position(pos.GetX()+60,pos.GetY()));
}
uint32_t GOIEPushareButton::GetHeight()
{
    return button.GetHeight();
}
void GOIEPushareButton::SetToDestroy()
{
    number.SetToDestroy();
    button.SetToDestroy();
    Destroy();
}
void GOIEPushareButton::SetNumber(uint32_t n)
{
    number.SetNumber(n);
}

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

Tavern::Tavern(Position pos,uint32_t f)
:Building(pos,f),change(false),ButtonState(false),ButtonDisable(false)
{
    GUIButton = 0;
    GUIButtonPoint = new uint32_t_pointer(&GUIButton);
    guiinfo = new void_pointer(&GUIList);
    ButtonStatePoint = new void_pointer(&ButtonState);
    ButtonDisablePoint = new void_pointer(&ButtonDisable);

    SafePointer::Pointers.push_back(GUIButtonPoint);
    SafePointer::Pointers.push_back(guiinfo);
    SafePointer::Pointers.push_back(ButtonStatePoint);
    SafePointer::Pointers.push_back(ButtonDisablePoint);

    InTavern.push_back(new NPCinTavern(position,fraction));

    mark.setTexture(Textures::textures->Ttavern);
}
Tavern::~Tavern()
{
    for(std::vector <NPCinTavern*>::iterator ite = InTavern.begin();ite!=InTavern.end();)
    {
        delete (*ite);
        ite = InTavern.erase(ite);
    }
    GUIButtonPoint->TurnOff();
    guiinfo->TurnOff();
    ButtonStatePoint->TurnOff();
    ButtonDisablePoint->TurnOff();
}

void Tavern::Step()
{
    Building::Step();
    if(InTavern.size()<3&& rand()%500==0)
    {
        InTavern.push_back(new NPCinTavern(position,fraction));
        change = true;
    }
    if(GUIButton<=InTavern.size()&&GUIButton>0)
    {
        if(InTavern[GUIButton-1]->price>(*Fraction::Fractions)[fraction]->GetEco()->GEE(4)->GetNonReservedAmount()
           ||(*Fraction::Fractions)[fraction]->GetMaxResidents()<=(*Fraction::Fractions)[fraction]->GetResidents())
            ButtonDisable=true;
        else
            ButtonDisable=false;

    }
    if(ButtonState)
    {
        AddObject add;
        add.Add(InTavern[GUIButton-1]->unit);
        InTavern[GUIButton-1]->unit->StartOccupying();
        InTavern[GUIButton-1]->ClearSlot();
        (*Fraction::Fractions)[fraction]->GetEco()->GEE(4)->ChangeAmount(-InTavern[GUIButton-1]->price);
        delete InTavern[GUIButton-1];
        InTavern.erase(InTavern.begin()+(GUIButton-1));
        change = true;
        ButtonState = false;
    }
    for(std::vector <NPCinTavern*>::iterator ite = InTavern.begin();ite!=InTavern.end();)
    {
        if((*ite)->timeleft>0)
        {
            (*ite)->timeleft--;
            ite++;
        }
        else
        {
            delete (*ite);
            ite = InTavern.erase(ite);
            change = true;
        }
    }
    if(perviousbutton != GUIButton||change)
        ChangeGuiInfo();
}

void Tavern::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 1;
    inf.fraction = GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}

void Tavern::Selected()
{
    MarkBuilding::Selected();
    OIPT * obj = new OIPT(Position(50,30),sf::Color(100+GetID()*30,0,0),Textures::textures->Ttavern,
                               Position(100,30),sf::Color(30,30,30),"Wooden Tavern");
    Markable::MarkedObjectInfo.Information.push_back(obj);

    SetHPonGUI();
    GUIButton = 0;

    if(fraction==2)
    {
        OIMBSelectOne * multi = new OIMBSelectOne(3,Position(200,40),Position(40,40),GUIButtonPoint);
        Markable::MarkedObjectInfo.Information.push_back(multi);

        OIDropDown * drd = new OIDropDown(Position(200,30),guiinfo);
        Markable::MarkedObjectInfo.Information.push_back(drd);
    }
}

void Tavern::ChangeGuiInfo()
{
    for(std::list<GUIObjectInfoElement*>::iterator ite = GUIList.begin();ite!=GUIList.end();)
    {
        GUIObjectInfoElement * gui = reinterpret_cast<GUIObjectInfoElement*>((*ite));
        delete gui;
        ite = GUIList.erase(ite);
    }
    if(GUIButton>0&&GUIButton<4&&GUIButton<=InTavern.size())
    {
        NPCinTavern * npc = InTavern[GUIButton-1];
        GUIObjectInfoElement * tex = new GOIEPTHorisontal(Position(-200,0),Position(170,34),Position(30,30),sf::Color(50,50,50),npc->ItemList);
        GUIList.push_back(tex);


        std::string  str = "";

        for(std::list <std::string>::iterator ite = npc->SkillList.begin();ite!=npc->SkillList.end();ite++)
        {
            str += (*ite) + " ";
        }
        tex = new GOIEText(Position(-200,0),Position(170,30),sf::Color(50,50,50),str);
        GUIList.push_back(tex);

        GOIEPushareButton * gui = new GOIEPushareButton(Position(-200,0),Position(20,20),sf::Color(100,100,0),ButtonStatePoint,ButtonDisablePoint);
        gui->SetNumber(npc->price);
        GUIList.push_back(gui);
    }
    perviousbutton = GUIButton;
    change = false;
}

TavernConstruction::TavernConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void TavernConstruction::Create()
{
    AddObject add;
    Tavern * m = new Tavern(position,fraction);
    add.Add(m);
}


TavernBlueprintButton::TavernBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(200,200,20));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void TavernBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void TavernBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void TavernBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Ttavern,
                               Position(100,50),sf::Color(30,30,30),"Build Wooden Tavern");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBTavern * ttt = new OICBTavern(OIText(Position(150,50),sf::Color(130,30,30),"CREATE"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
}
OICBTavern::OICBTavern(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBTavern::Create(Position pos)
{
    GOIECBTavern * g = new GOIECBTavern(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
GOIECBTavern::GOIECBTavern(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBTavern::~GOIECBTavern(){}
BuildingConstruction* GOIECBTavern::CreateBuildingConstruction()
{
    TavernConstruction * m = new TavernConstruction(Position(rand()%800+170,rand()%700),PlayerFraction);
    m->TESTCreateDemand(1,5);
    return m;
}



BoolPointer::BoolPointer():variable(false){point = new void_pointer(&variable);}
BoolPointer::~BoolPointer(){delete point;}


Tower::Tower(Position pos,uint32_t f):Building(pos,f),Creature(f)
{
    mark.setTexture(Textures::textures->Ttower);
    for(uint32_t i = 0;i < 2;i++)
    {
        Slot s;
        shooter.push_back(s);
    }
    //shooter.push_back()
    SlotPointer = new list_pointer(&RDV);
    RDV.push_back(&shooter);


}
Tower::Tower(Position pos,uint32_t f,Unit*u1,Unit*u2)
:Tower(pos,f)
{
    std::list <Slot>::iterator ite = shooter.begin();
    if(u1!=NULL)
    {
        (*ite).Occupant = u1;
        (*ite).reserved = true;
    }
    ite++;
    if(u2!=NULL)
    {
        (*ite).Occupant = u2;
        (*ite).reserved = true;
    }
}
Tower::~Tower()
{
    if(SlotPointer->DestroyMe())
        delete SlotPointer;
    for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
    {
        if((*ite).Occupant!=NULL)
            delete (*ite).Occupant;
    }
}
void Tower::Step()
{
    Building::Step();
    Unit * Occupants[2]={NULL,NULL};
    SeenRange = 0;
    uint32_t i = 0;
    bool reselect = false;
    for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
    {
        if((*ite).Occupant!=NULL)
        {
            if(State[i].variable)
            {
                State[i].variable=false;
                reselect = true;
                Kick(ite);
                i++;
                continue;
            }
            Occupants[i]=dynamic_cast<Unit*>((*ite).Occupant);
            if(Occupants[i]!=NULL)
            {
                SingleShot * ss=dynamic_cast<SingleShot*>(Occupants[i]->GetActiveTool());
                if(ss!=NULL&&ss->GetRange()>SeenRange)
                    SeenRange = ss->GetRange();
            }
        }
        i++;
    }
    if(SeenRange>0&&Look(position))
    {
        float distance = 10000;
        Info * inf = GetNearest(distance,position);
        if(distance < 10000)
        {
            i=0;
            for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
            {
                if(Occupants[i]==NULL){i++;continue;}

                SingleShot * singleshot = dynamic_cast<SingleShot*>(Occupants[i]->GetActiveTool());
                if(singleshot!=NULL)
                {
                    if(singleshot->GetActualReload()>0)
                        singleshot->Reload(100);
                    else
                        singleshot->Shoot(position,inf->position);
                }
                else
                {
                    float angle = position.angle(inf->position);
                    if(dynamic_cast<Item*>(Occupants[i]->GetActiveTool())!=NULL&&dynamic_cast<Item*>(Occupants[i]->GetActiveTool())->GetItemType()!=1)
                        angle += 180;
                   (*ite).Occupant->SetPosition(position.GetX()+cos(angle)*3,position.GetY()+sin(angle)*3+1);
                   Kick(ite);
                }
                i++;
            }
        }
    }
    if(reselect)
        Selected();
}
void Tower::CreateInfo(std::list<Info>& Objects)
{

    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 5;
    inf.fraction = Building::GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    inf.lpointer = SlotPointer;
    Objects.push_back(inf);
}
void Tower::Selected()
{
    MarkBuilding::Selected();
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Ttower,
                               Position(100,50),sf::Color(30,30,30),"Wooden Tower");
    Markable::MarkedObjectInfo.Information.push_back(obj);

    SetHPonGUI();

    if(fraction==2)
    {
        std::list<void_pointer*> p;
        for(uint32_t i = 0;i < 2;i++)
        {
            p.push_back(State[i].point);p.push_back(Disable[i].point);
        }
        std::list<CTextureReferenceIllusion> t;
        for(std::list <Slot>::iterator ite = shooter.begin();ite != shooter.end();ite++)
        {
            if((*ite).Occupant!=NULL)
            {
                Unit * u = dynamic_cast<Unit*>((*ite).Occupant);
                CTextureReferenceIllusion tri(*u->GetActiveTool()->GetImage().getTexture());
                t.push_back(tri);
            }
            else
                t.push_back(CTextureReferenceIllusion(Textures::textures->NoTexture));
        }
        OISlotElementsStorage * oises = new OISlotElementsStorage(p,t);
        Markable::MarkedObjectInfo.Information.push_back(oises);
    }
}

bool Tower::TypeComparation(std::list <Info>::iterator ite)
{
    if((*ite).type < 100)
        return true;
    return false;
}

void Tower::Kick(std::list<Slot>::iterator & ite)
{
    (*ite).Occupant->Activate();
    AddObject add;
    add.Add((*ite).Occupant);
    (*ite).Occupant = NULL;
    (*ite).reserved = false;
    (*ite).FirstHour = true;
}


TowerConstruction::TowerConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void TowerConstruction::Create()
{
    AddObject add;
    Tower * m = new Tower(position,fraction);
    add.Add(m);
}


TowerBlueprintButton::TowerBlueprintButton(Position pos,uint32_t * fraction)
:BlueprintButton(pos,fraction)
{

    shape.setSize(sf::Vector2f(16,16));
    shape.setFillColor(sf::Color(0,0,0));
    physicshape = new NRR(Position(20,20));
    mask = 0;
}
void TowerBlueprintButton::Step()
{
    shape.setPosition(sfLocalPos(PhysicObject::GetPosition()));
    BlueprintButton::Step();
}
void TowerBlueprintButton::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    BlueprintButton::draw(target,states);
    target.draw(shape,states);
}
void TowerBlueprintButton::Selected()
{
    BlueprintButton::Selected();
    Markable::MarkedObjectInfo.changed = true;
    OIPT * obj = new OIPT(Position(50,50),sf::Color(100+GetID()*30,0,0),Textures::textures->Ttower,
                               Position(100,50),sf::Color(30,30,30),"Combat Tower");
    Markable::MarkedObjectInfo.Information.push_back(obj);
    OICBTower * ttt = new OICBTower(OIText(Position(150,50),sf::Color(130,30,30),"CREATE Wooden Tower"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(ttt);
    OICBStoneTower * tt2 = new OICBStoneTower(OIText(Position(150,50),sf::Color(130,30,30),"CREATE Stone Tower"),*PlayerFraction);
    Markable::MarkedObjectInfo.Information.push_back(tt2);
}
OICBTower::OICBTower(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBTower::Create(Position pos)
{
    GOIECBTower * g = new GOIECBTower(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
GOIECBTower::GOIECBTower(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBTower::~GOIECBTower(){}
BuildingConstruction* GOIECBTower::CreateBuildingConstruction()
{
    TowerConstruction * m = new TowerConstruction(Position(0,0),PlayerFraction);
    m->TESTCreateDemand(1,10);
    return m;
}



StoneTower::StoneTower(Position pos,uint32_t f):Tower(pos,f)
{

    delete OutHP;
    OutHP = new HP(150,150);

    shape.setFillColor(sf::Color(170,170,170));

}


StoneTowerConstruction::StoneTowerConstruction(Position pos,uint32_t f)
:BuildingConstruction(pos,f)
{

}

void StoneTowerConstruction::Create()
{
    AddObject add;
    Tower * m = new StoneTower(position,fraction);
    add.Add(m);
}



OICBStoneTower::OICBStoneTower(OIText t,uint32_t pfr)
:OICreateButton(t,pfr){}
GUIObjectInfoElement * OICBStoneTower::Create(Position pos)
{
    GOIECBStoneTower * g = new GOIECBStoneTower(pos,GetTex().GetWah(),*static_cast<GOIEText*>(GetTex().Create(pos)),GetPlayerFraction());
    return g;
}
GOIECBStoneTower::GOIECBStoneTower(Position pos,Position dim,GOIEText & t,uint32_t fra)
:GOIECreateButton(pos,dim,t,fra){}
GOIECBStoneTower::~GOIECBStoneTower(){}
BuildingConstruction* GOIECBStoneTower::CreateBuildingConstruction()
{
    StoneTowerConstruction * m = new StoneTowerConstruction(Position(0,0),PlayerFraction);
    m->TESTCreateDemand(2,10);
    return m;
}





BarrackUnitStorage::BarrackUnitStorage(Unit * unit,std::list <UnitTask*> tasks,uint32_t RT)
:warrior(unit),Tasks(tasks),RelaseTime(RT){}

Barracks::Barracks(Position pos,uint32_t f,std::list <BarrackUnitStorage> bus)
:Building(pos,f)
{
    mark.setTexture(Textures::textures->Tbarracks);
    for(std::list <BarrackUnitStorage>::iterator ite = bus.begin();ite != bus.end();ite++)
        StoredUnits.push_back((*ite));

}
Barracks::~Barracks()
{
    for(std::list <BarrackUnitStorage>::iterator ite = StoredUnits.begin();ite != StoredUnits.end();ite++)
    {
        for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
            delete (*ite2);
        delete (*ite).warrior;
    }
}
void Barracks::Step()
{
    Building::Step();
    for(std::list <BarrackUnitStorage>::iterator ite = StoredUnits.begin();ite != StoredUnits.end();)
    {
        if((*ite).RelaseTime==0)
        {
            (*ite).warrior->SetPosition(position.GetX()+50,position.GetY());
            AddObject add;
            add.Add((*ite).warrior);
            for(std::list <UnitTask*>::iterator ite2 = (*ite).Tasks.begin();ite2 != (*ite).Tasks.end();ite2++)
                add.Add((*ite2));
            ite = StoredUnits.erase(ite);
        }
        else
        {
            (*ite).RelaseTime--;
            ite++;
        }
    }
}
void Barracks::CreateInfo(std::list<Info>& Objects)
{
    Info inf;
    inf.id = GetID();
    inf.position = GetPosition();
    inf.type = 1;
    inf.fraction = Building::GetFraction();
    inf.shapetype = GetShape()->GetShape();
    inf.shapesize = GetShape()->GetSize();
    Objects.push_back(inf);
}



