#ifndef CUSTOMBUILDINGS_H
#define CUSTOMBUILDINGS_H

#include "../include/Unit.h"
#include "../CustomGUIObjects/MultiButton.h"
#include "../CustomGUIObjects/RandomGUIObjects.h"

class OICreateButton:public ObjectInfo
{
    OIText tex;
    uint32_t PlayerFraction;
public:
    virtual GUIObjectInfoElement * Create(Position);
    OICreateButton(OIText,uint32_t);
    virtual ~OICreateButton();
    OIText GetTex();
    uint32_t GetPlayerFraction();
};

class GOIECreateButton:public Clickable2,public GUIObjectInfoElement
{
    GOIEText tex;
protected:
    uint32_t PlayerFraction;
    virtual PreBuilding * CreatePre(Position,Object*);
public:
    GOIECreateButton(Position,Position,GOIEText&,uint32_t);
    virtual void Istep();
    virtual void Idraw(sf::RenderTarget & target,sf::RenderStates states);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void ChangePosition(Position);
    virtual uint32_t GetHeight();
    virtual void SetToDestroy();
    virtual void Selected();
    virtual BuildingConstruction* CreateBuildingConstruction();
};




class Magazine:public Building
{
public:
    Magazine(Position,uint32_t);
    uint32_t GiveResources(uint32_t,uint32_t);
    virtual void CreateInfo(std::list<Info>&);
};
class MagazineConstruction:public BuildingConstruction
{
public:
    MagazineConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class MagazineBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    MagazineBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
class OICBMagazine:public OICreateButton
{
public:
    OICBMagazine(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBMagazine:public GOIECreateButton
{
public:
    GOIECBMagazine(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBMagazine();
    virtual BuildingConstruction* CreateBuildingConstruction();
};



class House:public Building
{
public:
    House(Position,uint32_t);
    ~House();
    virtual void CreateInfo(std::list<Info>&);
};
class HouseConstruction:public BuildingConstruction
{
public:
    HouseConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class HouseBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    HouseBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
class OICBHouse:public OICreateButton
{
public:
    OICBHouse(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBHouse:public GOIECreateButton
{
public:
    GOIECBHouse(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBHouse();
    virtual BuildingConstruction* CreateBuildingConstruction();
};




class Mine:public Building
{
    std::list <Slot> worker;
    uint32_t work;

    uint32_t materialtype;
    uint32_t workdemand;

    uint32_t_pointer * BarWork;
    uint32_t_pointer * BarWorkDemand;

    uint32_t emptyreserve;
public:
    Mine(Position,uint32_t);
    virtual ~Mine();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
    virtual void Selected();

    std::list <void*> RDV;
    list_pointer * SlotPointer;
};
class PreMineConstruction:public PreBuilding
{
public:
    PreMineConstruction(Position,Object*);
protected:
    virtual bool TileCheck();
};
class MineConstruction:public BuildingConstruction
{
public:
    MineConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class MineBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    MineBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
class OICBMine:public OICreateButton
{
public:
    OICBMine(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBMine:public GOIECreateButton
{
public:
    GOIECBMine(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBMine();
    virtual BuildingConstruction* CreateBuildingConstruction();
protected:
    virtual PreBuilding * CreatePre(Position,Object*);
};




class Workshop:public Building
{
    ResourceItem * res;
    std::list <Slot> worker;
    std::list <ResourceDemand> ResDem;
    uint32_t work;
    uint32_t workdemand;
    uint32_t_pointer * BarWork;
    uint32_t_pointer * BarWorkDemand;

    uint32_t RecipeNumber;
    uint32_t GatcheredResources;

    std::list <ResourceItem*> Ingredients;
    std::list <ResourceItem*> Trash;

    uint32_t GUIRecipe;
    uint32_t_pointer * GUIRecipeButtonPoint;

public:
    Workshop(Position,uint32_t);
    virtual ~Workshop();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
    virtual void Selected();

    std::list <void*> RDV;
    list_pointer * SlotPointer;
private:
    void Kick(Unit*);
    void CreateDemand();
    void PackForProduction();
    void ChangeRecipe(uint32_t);
};
class WorkshopConstruction:public BuildingConstruction
{
public:
    WorkshopConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class WorkshopBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    WorkshopBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
class OICBWorkshop:public OICreateButton
{
public:
    OICBWorkshop(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBWorkshop:public GOIECreateButton
{
public:
    GOIECBWorkshop(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBWorkshop();
    virtual BuildingConstruction* CreateBuildingConstruction();
};



class Forester:public Building
{
public:
    Forester(Position,uint32_t);
    ~Forester();
    virtual void Step();
    virtual void CreateInfo(std::list<Info>&);
};
class ForesterConstruction:public BuildingConstruction
{
public:
    ForesterConstruction(Position,uint32_t);
protected:
    virtual void Create();
};
class ForesterBlueprintButton:public BlueprintButton
{
    sf::RectangleShape shape;
public:
    ForesterBlueprintButton(Position,uint32_t*);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
};
class OICBForester:public OICreateButton
{
public:
    OICBForester(OIText,uint32_t);
    virtual GUIObjectInfoElement * Create(Position);
};
class GOIECBForester:public GOIECreateButton
{
public:
    GOIECBForester(Position,Position,GOIEText&,uint32_t);
    virtual ~GOIECBForester();
    virtual BuildingConstruction* CreateBuildingConstruction();
};





#endif // CUSTOMBUILDINGS_H
