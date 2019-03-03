#pragma once

#include "BuildMaterial.h"

enum Material
{
    TestMaterial = 0,
    wood,
    stone,
    iron,
    gold
};

class Resource
{

    public:
        Resource();
        virtual ~Resource();

        void AddBuildMaterialAttribute(uint32_t,uint32_t);
        BuildMaterial * build;
    protected:
    private:
};
