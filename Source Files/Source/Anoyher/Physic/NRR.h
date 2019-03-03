#pragma once

#include "Circle.h"

/// Non-Rotable Rectangle
class NRR:public PhysicShape
{
    public:
        NRR();
        NRR(Position);
        virtual ~NRR();

        virtual bool CollideV2(PhysicShape*,Position,Position);
        virtual bool InArea(Position,Position);

        void SetSize(Position);
        Position GetSize();

    protected:
    private:
    Position dimensions;

    Position CollideCircle(Circle*,Position,Position);
    bool CollideCircleV2(Circle*,Position,Position);
};

