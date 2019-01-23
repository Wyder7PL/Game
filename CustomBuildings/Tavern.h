#ifndef TAVERN_H
#define TAVERN_H

#include "../Races/TestRace.h"
#include "CustomBuildings.h"

class GOIEPushareButton:public Object,public GOIEvirtual
{
    GOIENumber number;
    GOIESingleClickButton button;
public:
    GOIEPushareButton(Position,Position,sf::Color,void_pointer*,void_pointer*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    void SetNumber(uint32_t);
};

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
    //void Kick(Unit*);
    void ChangeGuiInfo();
};
class TavernConstruction:public BuildingConstruction
{
public:
    TavernConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class TavernBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    TavernBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
class OICBTavern:public OICreateButton
{
public:
    OICBTavern(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBTavern:public GOIECreateButton
{
public:
    GOIECBTavern(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBTavern();
    virtual BuildingConstruction* CreateBuildingConstruction();
};

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
class StoneTower:public Tower
{
public:
    StoneTower(Position,uint32_t);
};
class TowerConstruction:public BuildingConstruction
{
public:
    TowerConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class StoneTowerConstruction:public BuildingConstruction
{
public:
    StoneTowerConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class TowerBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    TowerBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
class OICBTower:public OICreateButton
{
public:
    OICBTower(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBTower:public GOIECreateButton
{
public:
    GOIECBTower(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBTower();
    virtual BuildingConstruction* CreateBuildingConstruction();
};










class OICBStoneTower:public OICreateButton
{
public:
    OICBStoneTower(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBStoneTower:public GOIECreateButton
{
public:
    GOIECBStoneTower(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBStoneTower();
    virtual BuildingConstruction* CreateBuildingConstruction();
};












struct BarrackUnitStorage
{
    BarrackUnitStorage(Unit*,std::list<UnitTask*>,uint32_t);
    uint32_t RelaseTime;
    Unit * warrior;
    std::list <UnitTask*> Tasks;
};


class Barracks:public Building
{
    std::list <BarrackUnitStorage> StoredUnits;
public:
    Barracks(Position,uint32_t,std::list <BarrackUnitStorage>);
    virtual ~Barracks();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
};





#endif // TAVERN_H
