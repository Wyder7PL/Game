#pragma once

#include "../Markable/MarkBuilding.h"
#include "../HP/HP.h"
#include "ResourceDemand.h"
#include "../Fraction.h"

class Construction:public MarkBuilding
{
        bool demandchanged;
    public:
        Construction(Position,uint32_t=0);
        virtual ~Construction();
        virtual void Step();
        virtual void DealDamage(uint32_t,uint32_t);
        void GiveResource(uint32_t,uint32_t);
        void Dereserve(uint32_t,uint32_t);
        uint32_t GetFraction();
    protected:
        virtual void Create()=0;
        HP * ConstructionHP;
        uint32_t fraction;

        std::list <ResourceDemand> ResourcesDemanded;
        std::list <void*> RDV;

        ResourceDemand * GetDemand(uint32_t);

        list_pointer * RDPointer;
    private:
};
