#pragma once

#include "SafePointer.h"

class list_pointer:public SafePointer
{
    std::list <void*> * pointer;
public:
    list_pointer(std::list <void*>*);
    std::list <void*> * GetPointer();
};
