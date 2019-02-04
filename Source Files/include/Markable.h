#ifndef MARKABLE_H
#define MARKABLE_H

#include "ObjectInfo.h"
#include "AddObject.h"
#include "Functions.h"
#include "Fraction.h"
#include "Map.h"

#include "../Textures/Textures.h"

struct Info
{
    Info();
    uint32_t id = 0;
    Position position;
    uint32_t type = 0;
    uint32_t fraction = 0;
    uint32_t shapetype = 0;
    Position shapesize;
    list_pointer * lpointer=NULL;
};

/// //////////////////////// ///
/// Info type:               ///
/// 1.Building               ///
/// 2.Construction           ///
/// 3.Magazine               ///
/// 4.House                  ///
/// 5.Tower                  ///
/// 6.Mine                   ///
/// 7.Workshop               ///
/// ...                      ///
/// 20.Unit                  ///
/// ...                      ///
/// 100.Natural Resource     ///
/// 101.Tree                 ///
/// //////////////////////// ///


class Markable:public Object
{


    public:
        Markable(Position);
        virtual ~Markable();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        static ObjectInfoStorage MarkedObjectInfo;
        static void SetSelectedType(uint32_t);
        static uint32_t GetSelectedType();
        static void RestartSelectedType();
        static uint32_t SelectedType;///For TEST!

        virtual void DealDamage(uint32_t,uint32_t);
        virtual uint32_t GetFraction();
        virtual void CreateInfo(std::list<Info>&);

    protected:
        bool FirstStep();
        bool selected;

    private:
        bool firststep;
};

class Slot
{
public:
    Slot();
    Markable * Occupant;
    uint32_t type;
    bool reserved;
    bool FirstHour;
};

class TileOccupy
{
    void CountXGrid(Position,Position,uint32X2,uint32X2);
    void CountYGrid(Position,Position,uint32X2,uint32X2);
protected:
    TileOccupy();
    virtual ~TileOccupy();
    virtual bool SetGrid(Position,Position);
    Tile ** grid;
    uint32X2 currentgrid;
    uint32X2 currentgridstart;
};

class NonClickable:public Markable
{
public:
    NonClickable(Position);
    virtual ~NonClickable();
};

/// /////////////////////// ///
/// Selected type:          ///
/// 0 - None                ///
/// 1 - Building            ///
/// 2 - Unit                ///
/// 3 - Button              ///
/// 4 - PreBuilding         ///
/// 5 - Post 4              ///
/// 6 - Multi Unit Select   ///
/// 7 - Post 6              ///
/// /////////////////////// ///

class Clickable1:public Markable
{
    bool pressed;
public:
    Clickable1(Position);
    virtual ~Clickable1();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected()=0;
    virtual void Deselected();

};

class Clickable2:public Markable
{
    bool pressed;
public:
    Clickable2(Position);
    virtual ~Clickable2();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected()=0;
};

class MultiUnitSelection:public Object
{
    uint32_t SelectedCount;
    bool selecte;
    bool pressed;
    Position Begin;
    sf::RectangleShape shape;

    uint32_t GUISkilltpyeButton;
    uint32_t GUICommonOrderButton;
    uint32_t GUIEnemyIgnore;
protected:
    uint32_t_pointer * GUISkilltpyeButtonPoint;
    uint32_t_pointer * GUICommonOrderButtonPoint;
    uint32_t_pointer * GUIEnemyIgnorePoint;
    bool Afterselecte;
public:
    MultiUnitSelection();
    virtual ~MultiUnitSelection();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    uint32_t GetSelectedCount();
    bool AreSelected();
    bool AfterSelect();
    uint32_t GetSkillTypeButtonState();
    uint32_t GetCommonOrderButtonState();
    uint32_t GetIfEnemyIgnored();
private:
    Position AboveZero(Position);
    float LesserValue(float,float);
    friend class MarkUnit;
    friend class Unit;
    void increase();
    void decrease();
protected:
    virtual void GenerateGUIButtons()=0;
};

class MarkUnit:public Markable
{
    bool pervious;
    sf::CircleShape mark;

    bool ntm;///need to move?
    uint32_t ntmdenycooldown;
    Position Destination;
protected:
    static MultiUnitSelection * MUS;
    virtual void Desactivate();
    bool ForcedMove();
    Position ForcedDestination();
    virtual uint32_t GetSkillType()=0;
    virtual void QuickDeselect();
public:
    MarkUnit(Position);
    virtual ~MarkUnit();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    static void CreateMUS(MultiUnitSelection*);
    void MarkSize(float);
    virtual void CreateInfo(std::list<Info>&);
    void ForceDestination(Position);
};

/// /////////////////////////// ///
/// Skill type 1 << n-1         ///
/// 0 - None                    ///
/// 1 - Combat Only             ///
/// 2 - Close Combat            ///
/// 3 - Distance Combat         ///
/// /////////////////////////// ///

class MarkBuilding:public Clickable1,public TileOccupy
{
    sf::CircleShape mark;
public:
    MarkBuilding(Position);
    virtual ~MarkBuilding();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
    virtual void DealDamage(uint32_t,uint32_t)=0;
    void MarkSize(float);
protected:
};

class BlueprintButton:public Clickable1
{
    sf::RectangleShape border;
public:
    BlueprintButton(Position,uint32_t*);
    virtual ~BlueprintButton();
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    virtual void Selected();
protected:
    uint32_t * PlayerFraction;
};
#endif // MARKABLE_H
