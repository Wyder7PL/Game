#pragma once

#include "GUI/GUI.h"
#include "Map/Ground.h"
#include "GUI/GUIObjects/Menu/Menu.h"
#include "GUI/GUIObjects/MultiButtons/MUSGUICreate.h"
#include "GUI/GUIObjects/GOIEPointed.h"
#include "Textures/TextureTiles.h"
#include "Items/Recipes/Recipe.h"

#include "Events/EndOnNoFractionObjects.h"
#include "Events/OnBarracksDestroy.h"
#include "Events/MagazineSurvive.h"
#include "Tasks/CreateUnitsOnIDAproach.h"
#include "Tasks/CreateUnitsOnFractionAproach.h"
#include "Tasks/CUOAScanObject.h"
#include "Materials/Natural-Resources/CommonTree.h"
#include "Buildings/BuildingConstruction.h"
#include "Buildings/Tower/Barracks.h"
#include "Buildings/Tower/Tower.h"
#include "Buildings/Magazine/Magazine.h"
#include "Buildings/Forester/Forester.h"
#include "Buildings/Mine/Mine.h"
#include "Buildings/Workshop/Workshop.h"
#include "Buildings/House/HouseConstruction.h"
#include "Items/Weapions/SniperRifle.h"
#include "Items/Weapions/Sword.h"
#include "Items/Weapions/HookGun.h"
#include "Items/Weapions/Shootgun.h"
#include "Items/Weapions/Uzi.h"
#include "Skills/CloseCombat2.h"

#include "FastUnitCreate.h"
#include "Buildings/Tavern/Tavern.h"

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
