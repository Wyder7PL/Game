#pragma once

#include "GUIDoubleUint.h"
#include "../../../Functions.h"
#include "../../../Anoyher/Position.h"

class GUIBar:public Object,public GUIDoubleUint
{
    float BarWidth;
    sf::RectangleShape bar;
    sf::RectangleShape frame;
    public:
        GUIBar(Position,float,sf::Color,uint32_t_pointer*,uint32_t_pointer*);
        virtual ~GUIBar();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        virtual void ChangePosition(Position);
        virtual uint32_t GetHeight();
        virtual void SetToDestroy();
    protected:
    private:
    std::string U32PToString(uint32_t_pointer*);
};
