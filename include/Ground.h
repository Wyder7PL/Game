#ifndef GROUND_H
#define GROUND_H

#include "../Anoyher/MainControler.hpp"
#include "Map.h"
#include "Functions.h"
#include "../Textures/Textures.h"

class Ground:public Object
{
    sf::Shader shader;
    sf::Shader Gold;
    std::list <sf::Shader*> shaders;
    sf::Sprite (*ground);
    uint32_t ScreenWidth;
    uint32_t ScreenHeight;
    Tile ** maptiles;
    bool moved;
    public:
        Ground();
        ~Ground();

        void SetDimensions(uint32X2);
        void SetMapTiles(Tile*,uint32X2);

        virtual void Step();
        virtual void draw(sf::RenderTarget & target,sf::RenderStates states) const;

        uint32_t GetTilePosition(Position,uint32_t);
        void UpdateShaders();
    protected:
    private:
};

#endif // GROUND_H
