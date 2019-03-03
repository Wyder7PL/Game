#include "Tavern.h"

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
