#pragma once

#include "Construction.h"
//#include "GUIObjectCreateButton.h"
#include "../Pointers/uint32_t_pointer.h"
#include "../GUI/GUIObjects/HPViewer/OIBar.h"
#include "../AddObject.h"
#include "../Fraction.h"

#include "../HP/WoodenHP.h"

#include "Collision.h"

class Building:public MarkBuilding
{

    public:
        Building(Position,uint32_t=0);
        virtual ~Building();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        virtual void Selected();
        virtual void DealDamage(uint32_t,uint32_t);
        uint32_t GetFraction();
        virtual void CreateInfo(std::list<Info>&);
    protected:
        uint32_t AllHP;
        uint32_t FullHP;
        uint32_t_pointer * GUIHPPoint;
        uint32_t_pointer * GUIMHPPoint;
        HP * OutHP;
        HP * InHP;
        void SetHPonGUI();

        uint32_t fraction;
        sf::Sprite mark;

        sf::RectangleShape shape;
    private:
};

