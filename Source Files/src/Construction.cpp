#include "../include/Construction.h"

ResourceDemand::ResourceDemand(uint32_t ID,uint32_t demand)
:resID(ID),resdem(demand),resres(0)
{

}
uint32_t ResourceDemand::GetID()
{
    return resID;
}
uint32_t ResourceDemand::GetNonReserved()
{
    return resdem-resres;
}
uint32_t ResourceDemand::GetDemand()
{
    return resdem;
}
void ResourceDemand::Reserve(uint32_t rr)
{
    resres+=rr;
}
void ResourceDemand::Dereserve(uint32_t rr)
{
    if(resres <= rr)
        resres = 0;
    else
        resres-=rr;
}
void ResourceDemand::Give(uint32_t g)
{
    resdem-=g;
    resres-=g;
}

Construction::Construction(Position pos,uint32_t f)
:MarkBuilding(pos),demandchanged(true),fraction(f)
{
    RDPointer = new list_pointer(&RDV);
}

Construction::~Construction()
{
    if(selected)
    {
        SetSelectedType(0);
    }
    delete ConstructionHP;
    RDPointer->TurnOff();
}

void Construction::Step()
{
    if(ConstructionHP->GetHP() <=0)
    {
        Destroy();
        return;
    }
    if(demandchanged)
    {
        demandchanged = false;
        uint32_t Needed = 0;
        for(std::list <ResourceDemand>::iterator ite = ResourcesDemanded.begin();ite != ResourcesDemanded.end();ite++)
        {
            Needed+=(*ite).GetDemand();
        }
        if(Needed == 0)
        {
            Create();
            Destroy();
        }
    }
    MarkBuilding::Step();
}

void Construction::DealDamage(uint32_t damage,uint32_t type)
{
    ConstructionHP->TakeDamage(damage,type);
}

void Construction::GiveResource(uint32_t type,uint32_t amount)
{
    ResourceDemand * res = GetDemand(type);
    if(res!=NULL)
    {
        res->Give(amount);
        (*Fraction::Fractions)[fraction]->GetEco()->GEE(type)->UnReserve(amount);
        demandchanged = true;
    }
}
void Construction::Dereserve(uint32_t type,uint32_t amount)
{
    ResourceDemand * res = GetDemand(type);
    if(res!=NULL)
        res->Dereserve(amount);
}


uint32_t Construction::GetFraction()
{
    return fraction;
}

ResourceDemand * Construction::GetDemand(uint32_t type)
{
    for(std::list <ResourceDemand>::iterator ite = ResourcesDemanded.begin();ite != ResourcesDemanded.end();ite++)
    {
        if((*ite).GetID()==type)
            return &(*ite);
    }
    return NULL;
}
