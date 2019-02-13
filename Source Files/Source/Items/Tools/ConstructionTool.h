#pragma once
#include "Tool.h"
#include "../../projectile/Tool-projectile/constructiontool.h"

class  ConstructionTool:public Tool
{
protected:
    uint32_t MaxWorkPoints;
    uint32_t WorkPoints;
public:
    ConstructionTool(uint32_t);

    virtual uint32_t Build(Position,Position);
    virtual bool Refill(Position,Position);

    void setMaxWorkPoints(uint32_t);
    uint32_t GetMaxWorkPoints();
    void SetWorkPoints(uint32_t);
    uint32_t GetWorkPoints();

    void SetType(uint32_t t);
};
