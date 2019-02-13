#include "ViewInfo.hpp"

ViewInfo::ViewInfo()
:width(0),height(0),x(0),y(0)
{

}
ViewInfo::~ViewInfo()
{

}
void ViewInfo::SetView(int32_t X,int32_t Y)
{
    x = X;
    y = Y;
}
void ViewInfo::MoveView(int32_t X,int32_t Y)
{
    SetView(x+X,y+Y);
}
int32_t ViewInfo::GetX()
{
    return x;
}
int32_t ViewInfo::GetY()
{
    return y;
}

