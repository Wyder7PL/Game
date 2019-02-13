#pragma once

#include <string>
#include "../../Anoyher/Object.hpp"

class GUIObjectInfoElement
{
    public:
        GUIObjectInfoElement();
        virtual ~GUIObjectInfoElement();
        virtual void Step()=0;
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const=0;
        virtual uint32_t GetHeight();
        virtual void SetToDestroy()=0;
        virtual void ChangePosition(Position)=0;
        std::string intToStr(int32_t);
    protected:
    private:
};
