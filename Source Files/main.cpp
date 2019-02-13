#include "Source/Control.h"

int main()
{
    srand(time(NULL));

    Fonts::loadFonts();

    Control con;

    float frames = 0;


    float slow = 1;
    const float Step = 16*slow;
    float delta = 0.0f;
    float ConstStep = 0.0f;
    float last = clock() - 16*slow+1;
    do
    {

        delta = clock() - last;
        last+=delta;
        ConstStep+=delta;
        while(ConstStep > Step&&!Keyboard::Exit()&&RoundEnd::RoundEndState!=1)
        {
            con.Step();
            ConstStep -= Step;
            frames = clock();
        }
    }while(!Keyboard::Exit()&&RoundEnd::RoundEndState!=1);
    return 0;
}
