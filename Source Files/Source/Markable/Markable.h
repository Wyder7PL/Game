#pragma once

//
//#include "AddObject.h"
//#include "Functions.h"
//#include "Fraction.h"

//#include "../Textures/Textures.h"
#include "Info.h"
#include "../Anoyher/Object.hpp"
#include "../GUI/GUIObjects/ObjectInfo.h"

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
        static uint32_t SelectedType;

        virtual void DealDamage(uint32_t,uint32_t);
        virtual uint32_t GetFraction();
        virtual void CreateInfo(std::list<Info>&);

    protected:
        bool FirstStep();
        bool selected;

    private:
        bool firststep;
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
