#pragma once

#include "../Unit.h"

class Offense1Task:public UnitTask
{
    std::list <Position> CheckPoints;
    public:
        Offense1Task(uint32_t,std::list <Position>);
        virtual ~Offense1Task();
        virtual void Step(ObjectInserter&,Object*);
    protected:
    private:
};
