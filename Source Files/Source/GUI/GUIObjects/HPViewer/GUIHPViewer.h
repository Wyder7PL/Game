#pragma once

#include "GUIDoubleUint.h"
#include "../../../Fonts/Fonts.h"
#include "../../../Functions.h"

class GUIHPViewer:public Object,public GUIDoubleUint
{
    sf::Text shlash;
    public:
        GUIHPViewer(Position,/*sf::RectangleShape,*/uint32_t_pointer*,uint32_t_pointer*);
        virtual ~GUIHPViewer();
        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;
        virtual void ChangePosition(Position);
        virtual uint32_t GetHeight();
        virtual void SetToDestroy();
    protected:
    private:
    std::string U32PToString(uint32_t_pointer*);
};
