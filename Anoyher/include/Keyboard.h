#ifndef KEYBOARD_H
#define KEYBOARD_H

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdint.h>


class Keyboard
{
    sf::RenderWindow * okno;
    public:
        Keyboard();
        virtual ~Keyboard();
        void SetWindow(sf::RenderWindow*);



        void SetKeys();
        void ResetKeys();


protected:
    static int32_t mouseX;
    static int32_t mouseY;
    static bool mouseLW;
    static bool mouseLK;
    static bool mouseLP;
    static bool mouseLT;

    static bool mousePW;
    static bool mousePP;

    static bool up;
    static bool down;
    static bool left;
    static bool right;

    static bool exit;

    static bool f;
    static bool g;
    static bool i;

public:

    static int16_t MouseX();
    static int16_t MouseY();
    static bool MouseLW();
    static bool MouseLK();
    static bool MouseLP();
    static bool MousePW();
    static bool MousePP();
    static bool Up();
    static bool Down();
    static bool Left();
    static bool Right();
    static bool Exit();
    static bool F();
    static bool G();
    static bool I();
};

#endif // KEYBOARD_H
