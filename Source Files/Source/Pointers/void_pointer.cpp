#include "void_pointer.h"

void_pointer::void_pointer(void * v)
{
    pointer = v;
}
void * void_pointer::GetPointer()
{
    return pointer;
}
