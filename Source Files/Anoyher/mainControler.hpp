#ifndef MAINCONTROLER_HPP
#define MAINCONTROLER_HPP


#include "include/GraphicControler.hpp"
#include "include/PhysicControler.hpp"
#include <list>



class Object:public GraphicObject,public PhysicObject
{
    static uint32_t GlobalID;
    bool ToDestroy;
    bool Desactivated;
    uint32_t ID;
protected:
    void Destroy();
    virtual void Desactivate();
public:
    Object(Position);
    virtual ~Object();
    virtual void Step() = 0;
    virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const = 0;
    bool IsDestroyed();
    bool IsDesactivated();
    virtual void Activate();
    uint32_t GetID();
};

class ObjectInserter;


class EffectObject
{
    public:
        EffectObject();
        virtual ~EffectObject();

        virtual void Step(ObjectInserter&,Object*)=0;

        virtual void OnCollision(ObjectInserter&,Object*);

        virtual void OnDestroy(ObjectInserter&);

        uint32_t CreatorID();

        uint32_t AffectedID();

        void SetToClear();
        bool IsToClear();
    protected:
        uint32_t creator;

        uint32_t affected;

    private:
        bool toClear;
};

bool ObjectComparison(Object*,Object*);
bool EffectComparison(EffectObject*,EffectObject*);

class ObjectInserter
{
    friend class mainControler;
    list <Object*> Objects;
    list <EffectObject*> Effects;
public:
    void AddObject(Object*);
    void AddEffect(EffectObject*);
};

class mainControler
{
    GraphicControler Graphic;
    PhysicControler Physic;
    ObjectInserter Inserter;
    vector <Object*> Objects;
    list <EffectObject*> Effects;

public:
    mainControler();
    ~mainControler();

    void DestroyElements();

    void Step();
    void CreateObject(Object*);
    void CreateEffect(EffectObject*);

private:
    void Clear();
    void SortArrays();
    void ApplyEffects();
    void SymulatePhysicAndEffectsCollision();
    void EffectsLastWish();
    void AddObjects();

};




#endif
