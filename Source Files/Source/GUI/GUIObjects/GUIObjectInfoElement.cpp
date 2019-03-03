#include "GUIObjectInfoElement.h"


std::string GUIObjectInfoElement::intToStr(int32_t n)
{
     std::string tmp;
     if(n < 0) {
      tmp = "-";
      n = -n;
     }
     if(n > 9)
      tmp += intToStr(n / 10);
     tmp += n % 10 + 48;
     return tmp;
}

GUIObjectInfoElement::GUIObjectInfoElement()
{
    //ctor
}

GUIObjectInfoElement::~GUIObjectInfoElement(){}

uint32_t GUIObjectInfoElement::GetHeight()
{
    return 0;
}
