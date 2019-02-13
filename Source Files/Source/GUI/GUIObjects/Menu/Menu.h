#pragma once

#include "../../../Anoyher/Object.hpp"
#include "../MultiButtons/GOIEMBClickandDo.h"
#include "../../../Fonts/Fonts.h"


class Menu:public Object
{
    uint32_t levelbuttonstate;
    uint32_t_pointer * levelbuttonstatepointer;
    GOIEMBClickandDo * levelbuttons;
    sf::RectangleShape background;
    std::list <sf::Text*> ButtonDescription;
    public:
        Menu();
        virtual ~Menu();
        virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
        virtual void Step();
        void SetToDestroy();
        uint32_t Get();
    protected:
    private:
};
