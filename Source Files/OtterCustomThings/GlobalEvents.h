#ifndef GLOBALEVENTS_H
#define GLOBALEVENTS_H

#include "Tasks.h"

class RoundEnd:public Object
{
    uint32_t TillTheEnd;
    sf::Text TheLastThingYouSee;
public:
    static uint32_t RoundEndState;
    RoundEnd(Position,bool);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

class OnBuildingDestroy
{
protected:
    bool What;
    bool Prevent;
public:
    OnBuildingDestroy(bool);
    virtual ~OnBuildingDestroy();
};
class BuildingSurvive:public OnBuildingDestroy
{
    bool win;
    uint32_t Time;
public:
    BuildingSurvive(bool,uint32_t);
    virtual ~BuildingSurvive();
    virtual void Step();
};

class OnBarracksDestroy:public Barracks,public OnBuildingDestroy
{
public:
    OnBarracksDestroy(Position,uint32_t,std::list<BarrackUnitStorage>,bool);
};
class MagazineSurvive:public Magazine,public BuildingSurvive
{
public:
    MagazineSurvive(Position,uint32_t,bool,uint32_t);
    virtual void Step();
};


class CollisionFractionEffect:public EffectObject
{
    uint32_t fraction;
    bool collided;
    bool AfterCollision;
public:
    CollisionFractionEffect(uint32_t,uint32_t);
    void OnCollision(ObjectInserter&,Object*);
    void Step(ObjectInserter&,Object*);
};
class EndOnNoFractionObjects:public Object
{
    bool SoWhat;
    bool stillexists;
    uint32_t fraction;
public:
    EndOnNoFractionObjects(bool,uint32_t);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    void StillExists(bool);
};
#endif // GLOBALEVENTS_H
