#ifndef NATURALRESOURCE_H
#define NATURALRESOURCE_H

#include "Markable.h"
#include "HP.h"

class ResourceAvailability
{
    uint32_t amoumt;
    uint32_t type;
public:
    ResourceAvailability(uint32_t);
    uint32_t GetAmount();
    uint32_t GetType();
    void SetAmount(uint32_t);
    void SetType(uint32_t);
};

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


class TreeCollision:public EffectObject
{
    Position position;
    float TrunkRadius;
public:
    TreeCollision(uint32_t,float);
    virtual ~TreeCollision();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
};

class CommonTree:public NaturalResource,public TileOccupy
{
    sf::CircleShape shape;
    WoodenHP * hp;
public:
    CommonTree(Position);
    virtual ~CommonTree();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

    virtual bool TakeResource();

    virtual void DealDamage(uint32_t,uint32_t);
    virtual void CreateInfo(std::list<Info>&);


};
#endif // NATURALRESOURCE_H
