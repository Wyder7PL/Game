#include "NaturalResource.h"

NaturalResource::NaturalResource(Position pos,uint32_t Rtype)
:NonClickable(pos),RAv(Rtype)
{
    RDPointer = new list_pointer(&RDV);
    RDV.push_back(&RAv);
}

NaturalResource::~NaturalResource()
{
    RDPointer->TurnOff();
}
