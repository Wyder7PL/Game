#ifndef WRAPEDTEXT_H
#define WRAPEDTEXT_H

#include "../Fonts/Fonts.h"
#include "../Anoyher/MainControler.hpp"

class WrapedText
{
    Position position;
    Position dimensions;

    uint32_t characterSize;
    Position WordPosition;

    sf::Font font;

    std::vector <sf::Text> Texts;
    public:
        WrapedText(std::string,Position,Position,uint32_t);
        virtual ~WrapedText();
        void SetString(std::string);
        void SetDimensions(Position);
        void SetPosition(Position);
        void SetCharacterSize(uint32_t);
        void SetColor(sf::Color);
        void SetFont(sf::Font);
        void draw(sf::RenderTarget & target,sf::RenderStates states) const;
    protected:
    private:
    void CreateText(std::string);
};

#endif // WRAPEDTEXT_H
