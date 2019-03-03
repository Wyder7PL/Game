#pragma once

#include "SafePointer.h"

class void_pointer:public SafePointer
{
    void * pointer;
public:
    void_pointer(void*);
    void * GetPointer();
};
