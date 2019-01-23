#ifndef CONTROL_H
#define CONTROL_H

#include "GUI.h"
#include "Ground.h"
#include "..\CustomGUIObjects\Menu.h"
#include "..\OtterCustomThings\GlobalEvents.h"

class DebugNavigationPoint:public Object
{
    sf::CircleShape temp;
public:
    DebugNavigationPoint(Position);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

class FastUnitCreate
{
public:
    TestRace * WoodSpearI(Position,uint32_t,bool);
    TestRace * BowI(Position,uint32_t,bool);
    TestRace * MusketI(Position,uint32_t,bool);
    TestRace * WoodSwordII(Position,uint32_t,bool);
    TestRace * IronSwordII(Position,uint32_t,bool);
    TestRace * IronSwordHookII(Position,uint32_t,bool);
    TestRace * IronMinigunI(Position,uint32_t,bool);
    void CreateWithSimpleOffensiveTask(mainControler&,Unit*,Position);
    Offense1Task * GenerateSimpleOffensiveTask(mainControler&,Unit*,Position);
};

class Control
{
    Menu * menu;
    bool InMenu;


    mainControler mac;
    GUI * gui;
    ResourceStorage ReS;
    std::vector <Fraction*> fra;
    Map * MainMap;
    Ground * ground;

    public:
        Control();
        virtual ~Control();

        void TESTCREATEFRACTIONS();

        void AddObjects();

        void RefreshPointers();

        void MoveScreen();

        void Step();

    protected:
    private:

        void TESTCREATE();

        void Offensive();

        void Survival();

        void DeleteMenu();
};

#endif // CONTROL_H
