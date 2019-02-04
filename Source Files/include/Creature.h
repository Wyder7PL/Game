#ifndef CREATURE_H
#define CREATURE_H

#include <stdint.h>
#include "Skill.h"

class SightEffect:public EffectObject
{
    std::list <Info> Objects;
    uint32_t Steps;
    Object * ooo;
public:
    SightEffect(uint32_t);
    virtual ~SightEffect();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};

class Sight:public Object
{
    bool ready;
    bool destroy;
public:
    Sight(Position,float);
    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    std::list <Info> Objects;
    void SetReady();
    bool Ready();
    void Erase();
};

class Creature
{
    Sight * sight;
    bool blink;
    public:
        Creature(uint32_t);
        virtual ~Creature();

        uint32_t GetFraction();

        virtual bool Look(Position);
        void SetSeenRange(float);
        float GetSeenRange();
    protected:
        uint32_t Fraction;
        float SeenRange;
        std::list <Info> SeenObjects;
        Info* GetNearest(float&,Position);
        virtual bool TypeComparation(std::list <Info>::iterator)=0;
    private:
};

#endif // CREATURE_H
