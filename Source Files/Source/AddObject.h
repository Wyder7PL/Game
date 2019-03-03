#pragma once

#include "Anoyher/MainControler.hpp"

class AddObject
{
    friend class Control;
    static std::list <Object*> objects;
    static std::list <EffectObject*> effects;
    public:
        AddObject();
        virtual ~AddObject();
        void Add(Object*);
        void Add(EffectObject*);
    protected:
    private:
};

