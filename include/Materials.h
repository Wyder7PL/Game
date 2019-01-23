#ifndef MATERIALS_H
#define MATERIALS_H

#include <cstddef>
#include <stdint.h>
#include <vector>

enum Material
{
    TestMaterial = 0,
    wood,
    stone,
    iron,
    gold
};

class BuildMaterial
{
public:
    BuildMaterial(uint32_t,uint32_t);
    virtual ~BuildMaterial();
    uint32_t buildcost;
    uint32_t hp;
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

class ResourceStorage
{
    std::vector <Resource*> reslist;
public:
    ResourceStorage();
    virtual ~ResourceStorage();
    void DestroyElements();
    static std::vector <Resource*> * ResourcesList;
    void SetActive();
    void DefaultResourceListCreator();
};

#endif // MATERIALS_H
