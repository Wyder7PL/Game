#pragma once

#include <stdint.h>

class ResourceDemand
{
    uint32_t resID;
    uint32_t resdem;
    uint32_t resres;
public:
    ResourceDemand(uint32_t,uint32_t);
    uint32_t GetID();
    uint32_t GetNonReserved();
    uint32_t GetDemand();
    void Reserve(uint32_t);
    void Dereserve(uint32_t);
    void Give(uint32_t);
};
