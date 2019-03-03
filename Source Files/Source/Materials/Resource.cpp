#include "Resource.h"


Resource::Resource()
:build(NULL)
{

}

Resource::~Resource()
{
    if(build!=NULL)
        delete build;
}

void Resource::AddBuildMaterialAttribute(uint32_t bc,uint32_t h)
{
    build = new BuildMaterial(bc,h);
}

