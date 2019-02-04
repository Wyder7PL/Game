#ifndef ADDOBJECT_H
#define ADDOBJECT_H

#include "../Anoyher/MainControler.hpp"

class AddObject
{
    friend class Control;
    static std::list <Object*> objects;
    static std::list <EffectObject*> effects;
    std::list <Object*> * TESTPOINTER;
    public:
        AddObject();
        virtual ~AddObject();
        void Add(Object*);
        void Add(EffectObject*);
    protected:
    private:
};

#endif // ADDOBJECT_H
