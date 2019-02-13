#include "WrapedText.h"

WrapedText::WrapedText(std::string str,Position p,Position d,uint32_t cs)
:position(p),dimensions(d),characterSize(cs),WordPosition(p)
{
    SetString(str);
}

WrapedText::~WrapedText(){}

void WrapedText::SetString(std::string str)
{
    Texts.clear();

    std::string word = "";
    WordPosition = position;
    uint32_t CurrentLineWidth = 0;
    uint32_t CurrentWordWidth = 0;
    float width = characterSize*0.6;
    for(uint32_t i = 0;i < str.size();i++)
    {
        if(CurrentLineWidth != CurrentWordWidth)
        {
            if(CurrentLineWidth*width > dimensions.GetX())
            {
                CurrentLineWidth = CurrentWordWidth;
                WordPosition.SetY(WordPosition.GetY()+characterSize);
                WordPosition.SetX(position.GetX());
            }
        }
        if(str[i] == 32)
        {
            CurrentLineWidth++;
            CreateText(word);
            WordPosition.SetX(position.GetX()+CurrentLineWidth*width);
            word = "";
            CurrentWordWidth = 0;
        }
        else if(i+1 == str.size())
        {
            word+=str[i];
            CreateText(word);
            break;
        }
        if(str[i] != 32)
        {
            word+=str[i];
            CurrentLineWidth++;
            CurrentWordWidth++;
        }
    }
}

void WrapedText::CreateText(std::string str)
{
    sf::Text text;
    text.setFont(Fonts::SMB);
    text.setString(str);
    text.setCharacterSize(characterSize);
    text.setPosition(WordPosition.GetX(),WordPosition.GetY());
    Texts.push_back(text);
}

void WrapedText::SetDimensions(Position d)
{
    dimensions = d;
}
void WrapedText::SetPosition(Position p)
{
    for(uint32_t i = 0;i < Texts.size();i++)
        Texts[i].move(p.GetX()-position.GetX(),p.GetY()-position.GetY());
    position = p;

}
void WrapedText::SetCharacterSize(uint32_t cs)
{
    characterSize = cs;
}
void WrapedText::SetColor(sf::Color col)
{
    for(std::vector <sf::Text>::iterator ite = Texts.begin();ite!=Texts.end();ite++)
        (*ite).setColor(col);
}
void WrapedText::SetFont(sf::Font f)
{
    font = f;
}
void WrapedText::draw(sf::RenderTarget & target,sf::RenderStates states) const
{
    for(uint32_t i = 0;i < Texts.size();i++)
        target.draw(Texts[i],states);

}
