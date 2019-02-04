#include "include/Control.h"

int main()
{
    srand(time(NULL));

    Fonts::loadFonts();

    Control con;

    float frames = 0;


    float slow = 1;
    const float Krok = 16*slow;
    float delta = 0.0f;
    float stalokrokowa = 0.0f;
    float ostatni = clock() - 16*slow+1;
    do
    {

        delta = clock() - ostatni;
        ostatni+=delta;
        stalokrokowa+=delta;
        while(stalokrokowa > Krok&&!Keyboard::Exit()&&RoundEnd::RoundEndState!=1)
        {
            con.Step();
            stalokrokowa -= Krok;
            frames = clock();
        }
    }while(!Keyboard::Exit()&&RoundEnd::RoundEndState!=1);
    return 0;
}
