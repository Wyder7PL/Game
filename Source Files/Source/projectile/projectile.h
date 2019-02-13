#pragma once
#include "../Buildings/Building.h"
//#include "NaturalResource.h"

class projectile:public Object
{
    uint32_t fractions;
    public:
        projectile(Position,uint32_t);
        virtual ~projectile();
        uint32_t GetFractions();
        void SetFractions(uint32_t);
};
