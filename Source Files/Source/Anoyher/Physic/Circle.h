#pragma once

#include "PhysicShape.h"
#include "CollideAll.h"


class Circle:public PhysicShape
{
    public:
        Circle();
        Circle(float);
        virtual ~Circle();

        virtual bool CollideV2(PhysicShape*,Position,Position);
        virtual bool InArea(Position,Position);
        virtual Position GetClosestEdge(Position,Position,float);

        void SetRadius(float);
        Position GetSize();

    protected:
    private:
    float radius;

    Position CollideCircle(Circle*,Position,Position);
    bool CollideCircleV2(Circle*,Position,Position);
    bool CollideAllV2(CollideAll*,Position,Position);
};

