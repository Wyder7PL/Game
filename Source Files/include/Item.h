#ifndef ITEM_H
#define ITEM_H

#include <stdint.h>
#include "projectile.h"

class Item
{
    uint32_t ItemType;
    float Weight;
    public:
        Item(uint32_t);
        virtual ~Item();
        uint32_t GetItemType();
        float GetWeight();
        void SetFractions(uint32_t);
        virtual float GetSeenRange();
        sf::Sprite & GetImage();
    protected:
        void SetItemType(uint32_t);
        void SetWeight(float);
        uint32_t fractions;
        sf::Sprite image;
    private:
};

/// ///////////////////////// ///
/// Item Type:                ///
/// 0 - None                  ///
/// 1 - Combat                ///
/// 2 - Tool                  ///
/// 3 - Resource              ///
/// 4 - Armor                 ///
/// ///////////////////////// ///


class CloseCombatItem: public Item
{
    float range;
    uint32_t speed;
    uint32_t cooldown;
    public:
        CloseCombatItem(uint32_t);
        virtual ~CloseCombatItem();
        virtual bool Attack(Position,Position)=0;
        virtual float GetSeenRange();
    protected:
        float GetRange();
        void SetRange(float);
        float GetSpeed();
        void SetSpeed(uint32_t);
        uint32_t GetCooldown();
        void SetCooldown(uint32_t);
    private:
};

class Spear:public CloseCombatItem
{
    public:
        Spear(uint32_t);
        virtual ~Spear();
        virtual bool Attack(Position,Position);
    protected:
    private:
};

class Sword:public CloseCombatItem
{
   public:
       Sword(uint32_t);
       virtual bool Attack(Position,Position);
};

class SingleShot:public Item
{
    uint32_t damage;
    float range;
    float accuarity;//1-3.14//
    uint32_t cooldown;
    uint32_t shootrate;
    uint32_t fullmagazine;
    uint32_t magazine;
    float reloadtime;
    float actualreload;
    public:
        SingleShot(uint32_t);
        virtual ~SingleShot();
        virtual bool Shoot(Position,Position);
        virtual void Reload(uint32_t);
        uint32_t GetActualReload();
        virtual float GetSeenRange();

        float GetRange();
    protected:
        virtual void CreateBullet(Position,Position);
        virtual float RandomBullet();
        virtual bool Charged();

        void SetDamage(uint32_t);
        uint32_t GetDamage();


        void SetRange(float);
        float GetAccuarity();
        void SetAccuarity(float);
        uint32_t GetCooldown();
        void SetCooldown(uint32_t);
        uint32_t GetShootRate();
        void SetShootRate(uint32_t);
        uint32_t GetFullMagazine();
        void SetFullMagazine(uint32_t);
        uint32_t GetMagazine();
        void SetMagazine(uint32_t);
        uint32_t GetReloadTime();
        void SetReloadTime(uint32_t);

        void SetActualReload(uint32_t);
    private:
};

class SniperRifle:public SingleShot
{
public:
    SniperRifle(uint32_t);
};

class Shootgun:public SingleShot
{
public:
    Shootgun(uint32_t);
protected:
    virtual void CreateBullet(Position,Position);
};

class MiniGun:public SingleShot
{
public:
    MiniGun(uint32_t);
    virtual ~MiniGun();
};

class Uzi:public SingleShot
{
public:
    Uzi(uint32_t);
    virtual ~Uzi();
};

class Musket:public SingleShot
{
public:
    Musket(uint32_t);
};

class HookGun:public SingleShot
{
public:
    HookGun(uint32_t);
    virtual ~HookGun();
protected:
    virtual void CreateBullet(Position,Position);
};

class Bow:public SingleShot
{
    uint32_t charge;
    uint32_t chargetime;
public:
    Bow(uint32_t);
    virtual ~Bow();


    virtual float GetSeenRange();

    virtual bool Charged();
    virtual void CreateBullet(Position,Position);

    void SetChargeTime(uint32_t);
};

class Tool:public Item
{
    float range;
    uint32_t speed;


    uint32_t Type;

protected:
    uint32_t Price;
    uint32_t Charge;
public:
    Tool(uint32_t);

    float GetRange();
    void SetRange(float);
    uint32_t GetSpeed();
    void SetSpeed(uint32_t);


    virtual void SetType(uint32_t);
    uint32_t GetType();

    virtual float GetSeenRange();
};

class  ConstructionTool:public Tool
{
protected:
    uint32_t MaxWorkPoints;
    uint32_t WorkPoints;
public:
    ConstructionTool(uint32_t);

    virtual uint32_t Build(Position,Position);
    virtual bool Refill(Position,Position);

    void setMaxWorkPoints(uint32_t);
    uint32_t GetMaxWorkPoints();
    void SetWorkPoints(uint32_t);
    uint32_t GetWorkPoints();

    void SetType(uint32_t t);
};
class PrimaryCTool:public ConstructionTool
{
public:
    PrimaryCTool(uint32_t);
};

class ResourceItem:public Item
{
    uint32_t type;
    uint32_t amount;
    uint32_t maxamount;
public:
    ResourceItem(uint32_t,uint32_t);
    uint32_t GetType();
};

class StorageComponent:public Tool
{
protected:
    ResourceItem * res;
public:
    StorageComponent(uint32_t);
    uint32_t Store(Position,Position,uint32_t,uint32_t);
    uint32_t Extract(Position,Position,uint32_t,uint32_t);
};

class GatherTool:public StorageComponent
{
public:
    GatherTool(uint32_t);
    virtual uint32_t Gather(Position,Position,uint32_t);
};

class MiningTool:public StorageComponent
{
public:
    MiningTool(uint32_t);
};

class ToolBox:public StorageComponent
{
public:
    ToolBox(uint32_t);
    ResourceItem * GetExtractedItem();
};

class RecipeIngredient
{
protected:
    uint32_t type;
    uint32_t amount;
public:
    RecipeIngredient(uint32_t,uint32_t);
    uint32_t GetType();
    uint32_t GetAmount();
};

class RecipeProduct:public RecipeIngredient
{
    uint32_t chance;
public:
    RecipeProduct(uint32_t,uint32_t,uint32_t=1);
    uint32_t GetChance();
};

class Recipe
{
public:
    std::list <RecipeIngredient> RecIng;
    std::list <RecipeProduct> RecPro;
    static Recipe * Recipes;
    static uint32_t RecipesAmount();
    uint32_t WorkDemand;
};

Recipe * CreateRecipes();

class Armor:public Item
{
public:
    Armor(uint32_t);
    virtual uint32_t DecreaseDamage(uint32_t,uint32_t)=0;
protected:
    uint32_t GTZ(uint32_t,uint32_t);
    uint32_t GTO(uint32_t,uint32_t);
};

class WoodenArmor:public Armor
{
public:
    WoodenArmor(uint32_t);
    virtual uint32_t DecreaseDamage(uint32_t,uint32_t);
};
class IronPlateArmor:public Armor
{
public:
    IronPlateArmor(uint32_t);
    virtual uint32_t DecreaseDamage(uint32_t,uint32_t);
};


#endif // ITEM_H
