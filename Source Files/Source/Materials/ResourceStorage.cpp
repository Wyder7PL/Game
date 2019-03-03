#include "ResourceStorage.h"

std::vector <Resource*> * ResourceStorage::ResourcesList = NULL;

ResourceStorage::ResourceStorage()
{

}

ResourceStorage::~ResourceStorage()
{
    DestroyElements();
}
void ResourceStorage::DestroyElements()
{
    if(ResourceStorage::ResourcesList == &reslist)
        ResourceStorage::ResourcesList = NULL;
    for(std::vector <Resource*>::iterator ite = reslist.begin();ite!=reslist.end();ite++)
        delete (*ite);
    reslist.clear();
}

void ResourceStorage::SetActive()
{
    ResourceStorage::ResourcesList = &reslist;
}

void ResourceStorage::DefaultResourceListCreator()
{
    Resource * res = new Resource();
    res->AddBuildMaterialAttribute(3,4);
    reslist.push_back(res);

    res = new Resource();
    res->AddBuildMaterialAttribute(3,4);
    reslist.push_back(res);

    res = new Resource();
    res->AddBuildMaterialAttribute(3,7);
    reslist.push_back(res);

    res = new Resource();
    res->AddBuildMaterialAttribute(20,10);
    reslist.push_back(res);

    res = new Resource();
    reslist.push_back(res);

}
