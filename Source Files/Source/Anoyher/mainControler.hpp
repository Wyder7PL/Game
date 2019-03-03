#pragma once


#include "ObjectInserter.hpp"


class mainControler
{
    GraphicControler Graphic;
    PhysicControler Physic;
    ObjectInserter Inserter;
    std::vector <Object*> Objects;
    std::list <EffectObject*> Effects;

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

