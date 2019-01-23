#include "../include/SafePointer.h"

std::list <SafePointer*> SafePointer::Pointers;

SafePointer::SafePointer()
:toDestroy(false),wait(10)
{
    //ctor
}

SafePointer::~SafePointer()
{
    //dtor
}

bool SafePointer::DestroyMe()
{
    return toDestroy;
}
void SafePointer::TurnOff()
{
    toDestroy = true;
}
bool SafePointer::StepnWait()
{
    if(toDestroy)
    {
        if(wait==0)
            return true;
        wait--;
    }
    return false;
}


void_pointer::void_pointer(void * v)
{
    pointer = v;
}
void * void_pointer::GetPointer()
{
    return pointer;
}


uint32_t_pointer::uint32_t_pointer(uint32_t * poi)
{
    pointer = poi;
}

uint32_t * uint32_t_pointer::GetPointer()
{
    return pointer;
}

list_pointer::list_pointer(std::list <void*> * poi)
{
    pointer = poi;
}
std::list <void*> * list_pointer::GetPointer()
{
    return pointer;
}
