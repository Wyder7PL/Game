#include "../include/GraphicObject.h"
#include "Keyboard.h"

using namespace std;

class ViewInfo
{
    int32_t width,height,x,y;
public:
    ViewInfo();
    ~ViewInfo();
    void SetView(int32_t,int32_t);
    void MoveView(int32_t,int32_t);
    int32_t GetX();
    int32_t GetY();
};

class GraphicControler
{
    sf::RenderWindow Scena;

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
