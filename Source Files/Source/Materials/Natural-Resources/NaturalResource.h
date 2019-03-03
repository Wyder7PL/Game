#pragma once

#include "../../Markable/NonClickable.h"
#include "ResourceAvailability.h"


class NaturalResource:public NonClickable
{

    public:
        NaturalResource(Position,uint32_t);
        virtual ~NaturalResource();
        virtual bool TakeResource()=0;
protected:
    uint32_t hphandle;
    ResourceAvailability RAv;
    std::list <void*> RDV;
    list_pointer * RDPointer;
    private:
};
