#pragma once

#include "Circle.h"
#include "CollideAll.h"
#include "NRR.h"


class PhysicObject
{
    public:
        PhysicObject(Position);

        virtual ~PhysicObject();

        void Collide(PhysicObject*);

        bool CollideV2(PhysicObject*);

        bool InArea(Position);

        void ApplyStoredForces();

        void Push(Position);

        Position GetPosition();
        void SetPosition(float,float);

        Position GetClosestEdge(Position,float);

        uint32_t GetMask();
        void SetMask(uint32_t);

        float GetMass();

        PhysicShape * GetShape();

        bool ToClear();

        uint32_t VectorID;
    protected:
        void SetMass(float);
        void SetMaxSpeed(float);

        Position position;

        uint32_t mask;

        PhysicShape * physicshape;

        bool toClear;

        float stopping;

    private:
        Position Force;
        Position AditionalForce;

        float speed;
        float mass;
        float braking;
};
