#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

class GraphicObject:public sf::Drawable
{


    int32_t Zindex;

    public:
        GraphicObject();
        virtual ~GraphicObject();

        virtual void draw(sf::RenderTarget&,sf::RenderStates) const = 0;

        int32_t GetZIndex();
        void SetZIndex(int32_t);

        bool ToClear();
    protected:
        bool toClear;

    private:
};

#endif // GRAPHICOBJECT_H
