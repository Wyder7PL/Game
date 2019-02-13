#pragma once

#include <vector>
#include <list>

#include "PhysicObject.h"
#include "../uint32X2.hpp"

class PhysicControler
{
    std::vector <PhysicObject*> MainPhysicObjContainer;

    std::vector <std::vector<PhysicObject*>> MaskSortedObj;

    public:
        PhysicControler();
        ~PhysicControler();

        void MaskSort();

        void SimulatePhysic();

        void SimulatePhysicV2();

        void TESTaddPhysic(PhysicObject*);

        void ClearArray();

        std::list <uint32X2> Collisions;

};
