#include "uint32_t_pointer.h"

uint32_t_pointer::uint32_t_pointer(uint32_t * poi)
{
    pointer = poi;
}

uint32_t * uint32_t_pointer::GetPointer()
{
    return pointer;
}
