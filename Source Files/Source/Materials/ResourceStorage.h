#pragma once

#include <vector>
#include "Resource.h"

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

