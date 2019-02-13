#pragma once


#include <stdint.h>
#include "../Materials/ResourceStorage.h"
#include "EconomyElement.h"

class Economy
{
    std::vector <EconomyElement*> Elements;
    public:
        Economy();
        virtual ~Economy();

        void ReSet();
        EconomyElement* GEE(uint32_t);
};

