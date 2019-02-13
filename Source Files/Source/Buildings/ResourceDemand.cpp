#include "ResourceDemand.h"

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
