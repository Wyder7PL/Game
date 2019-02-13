#pragma once
#include "../Item.h"

class Tool:public Item
{
    float range;
    uint32_t speed;


    uint32_t Type;

protected:
    uint32_t Price;
    uint32_t Charge;
public:
    Tool(uint32_t);

    float GetRange();
    void SetRange(float);
    uint32_t GetSpeed();
    void SetSpeed(uint32_t);


    virtual void SetType(uint32_t);
    uint32_t GetType();

    virtual float GetSeenRange();
};
