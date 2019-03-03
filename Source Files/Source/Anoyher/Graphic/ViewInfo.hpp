#pragma once

#include <stdint.h>


class ViewInfo
{
    int32_t width,height,x,y;
public:
    ViewInfo();
    ~ViewInfo();
    void SetView(int32_t,int32_t);
    void MoveView(int32_t,int32_t);
    int32_t GetX();
    int32_t GetY();
};
