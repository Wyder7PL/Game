#include "SafePointer.h"

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
