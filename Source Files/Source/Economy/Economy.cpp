#include "Economy.h"

Economy::Economy()
{
    ReSet();
}

Economy::~Economy()
{
    for(std::vector <EconomyElement*>::iterator ite = Elements.begin();ite!=Elements.end();ite++)
        delete (*ite);
    Elements.clear();
}

void Economy::ReSet()
{
    EconomyElement * eco;
    for(uint32_t i = 0;i < ResourceStorage::ResourcesList->size();i++)
    {
        eco = new EconomyElement();
        Elements.push_back(eco);
    }
}

EconomyElement* Economy::GEE(uint32_t e)
{
    if(e<Elements.size())
        return Elements[e];
    return NULL;
}
