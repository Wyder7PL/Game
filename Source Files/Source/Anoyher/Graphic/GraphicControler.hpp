#pragma once

#include "ViewInfo.hpp"
#include "GraphicObject.h"
#include "../Keyboard.h"

class GraphicControler
{
    sf::RenderWindow Scene;

    std::vector <GraphicObject*> GraphicObjects;

    Keyboard key;
public:
    static ViewInfo viewinfo;

    GraphicControler();

    ~GraphicControler();

    void IndexSort();

    void DrawEverything();

    void TESTCreateGraphic(GraphicObject*);

    void ClearArray();

    void SetKeyboard();

    void SetView(int32_t,int32_t);

};

bool GraphicIndexComparation(GraphicObject*,GraphicObject*);
