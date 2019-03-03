#pragma once

#include <cstddef>
#include <stdint.h>


class BuildMaterial
{
public:
    BuildMaterial(uint32_t,uint32_t);
    virtual ~BuildMaterial();
    uint32_t buildcost;
    uint32_t hp;
};
