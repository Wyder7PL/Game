#ifndef MENU_H
#define MENU_H

#include "MultiButton.h"


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

#endif // MENU_H
