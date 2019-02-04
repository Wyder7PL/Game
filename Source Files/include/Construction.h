#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include "Markable.h"
#include "HP.h"

class ResourceDemand
{
    uint32_t resID;
    uint32_t resdem;
    uint32_t resres;
public:
    ResourceDemand(uint32_t,uint32_t);
    uint32_t GetID();
    uint32_t GetNonReserved();
    uint32_t GetDemand();
    void Reserve(uint32_t);
    void Dereserve(uint32_t);
    void Give(uint32_t);
};

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

#endif // CONSTRUCTION_H
