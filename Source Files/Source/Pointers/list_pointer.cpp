#include "list_pointer.h"

list_pointer::list_pointer(std::list <void*> * poi)
{
    pointer = poi;
}
std::list <void*> * list_pointer::GetPointer()
{
    return pointer;
}
