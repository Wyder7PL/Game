#pragma once


#include "Markable.h"

class NonClickable:public Markable
{
public:
    NonClickable(Position);
    virtual ~NonClickable();
};
