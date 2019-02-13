#pragma once


#include "Object.hpp"

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


bool EffectComparison(EffectObject*,EffectObject*);

