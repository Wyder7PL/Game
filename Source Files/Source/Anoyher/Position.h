#pragma once

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>


#include <stdint.h>
#include <cstddef>
#include <math.h>


class Position
{
    float x = 0;
    float y = 0;
public:
    Position(float,float);
    Position(const Position&);
    float GetX();
    float GetY();
    void Set(float,float);
    void SetX(float);
    void SetY(float);
    void operator =(const float&);

    float distance(Position);
    float angle(Position);
    Position GMP(float,float);
};

