#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Building.h"
#include "NaturalResource.h"

class projectileEff:public EffectObject
{
    uint32_t fractions;
public:
    projectileEff();
    virtual ~projectileEff();
    uint32_t GetFractions();
    void SetFractions(uint32_t);
};

class projectile:public Object
{
    uint32_t fractions;
    public:
        projectile(Position,uint32_t);
        virtual ~projectile();
        uint32_t GetFractions();
        void SetFractions(uint32_t);
};

class spearEff:public projectileEff
{
public:
    spearEff(uint32_t);
    virtual ~spearEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};

class spear:public projectile
{
    sf::CircleShape TEST;
    public:
        spear(Position,uint32_t);
        virtual ~spear();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

class swordEff:public projectileEff
{
    uint32_t damage;
public:
    swordEff(uint32_t,uint32_t);
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};

class sword:public projectile
{
    sf::CircleShape TEST;
    public:
        sword(Position,uint32_t,float,uint32_t);

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

};

class bulletEff:public projectileEff
{
    Position pos;
    uint32_t pierce;
    uint32_t damage;
public:
    bulletEff(uint32_t,uint32_t);
    virtual ~bulletEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};

class bullet:public projectile
{
    uint32_t damage;
    uint32_t step;
    sf::CircleShape TEST;
    public:
        bullet(Position,uint32_t,uint32_t);
        virtual ~bullet();

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        uint32_t Existance;

    protected:
    private:
};

class chaineffect:public Object
{
    sf::CircleShape TEST;
    public:
        chaineffect(Position);
        virtual ~chaineffect();

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        uint32_t Existance;
};

class hookEff:public projectileEff
{
    Position pos;
    uint32_t pierce;
    uint32_t step;
public:
    hookEff(uint32_t);
    virtual ~hookEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};

class hook:public projectile
{
    uint32_t step;
    sf::CircleShape TEST;
    public:
        hook(Position,uint32_t);
        virtual ~hook();

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        uint32_t Existance;

    protected:
    private:
};


class SCMEff:public projectileEff
{
    uint32_t ID;
public:
    SCMEff(uint32_t,uint32_t);
    virtual ~SCMEff();
    void Step(ObjectInserter&,Object*);
    void OnCollision(ObjectInserter&,Object*);
    void OnDestroy(ObjectInserter&);
    void ChangeAffected(uint32_t);
    virtual void Communicate(Object*)=0;
};

class SCM:public projectile
{
public:
    SCM(SCMEff*,uint32_t);
    virtual ~SCM();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};


class constructiontoolEff:public projectileEff
{
    uint32_t Rtype;
public:
    constructiontoolEff(uint32_t,uint32_t);
    virtual ~constructiontoolEff();
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
class constructiontool:public projectile
{
    sf::CircleShape TEST;
public:
    constructiontool(Position,uint32_t,uint32_t);
    virtual ~constructiontool();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

class gathertollEff:public projectileEff
{
    uint32_t id;
public:
    gathertollEff(uint32_t,uint32_t);
    virtual void Step(ObjectInserter&,Object*);
    virtual void OnCollision(ObjectInserter&,Object*);
    virtual void OnDestroy(ObjectInserter&);
};
class gathertoll:public projectile
{
    uint32_t id;
public:
    gathertoll(Position,uint32_t,uint32_t);
    virtual ~gathertoll();

    virtual void Step();
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
};

#endif // PROJECTILE_H













