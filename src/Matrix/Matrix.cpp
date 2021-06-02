#include <Arduino.h>
#include <MaxMatrix.h>
#include <Matrix/Symbols/Symbols.h>
/*
  8x8 Dot Matrix w/ MAX7219
  modified on 7 March 2019
  by Saeed Hosseini @ Electropeak
  https://electropeak.com/learn/
*/
int DIN = 7;
int CLK = 6;
int CS = 5;
int maxInUse = 1;
bool isReady = true;

MaxMatrix m(DIN, CS, CLK, maxInUse);


void setupMatrix()
{
    m.init();
    m.setIntensity(3);
    delay(100);
}

void DrawCounter()
{
    for (int i = 0; i < 8; i++)
    {
        m.setColumn(i, smiley[i]);
    }
    // delay(1000);
    // for (int i = 0; i < 8; i++)
    // {
    //     m.setColumn(i, three[i]);
    // }
    // delay(1000);
    // for (int i = 0; i < 8; i++)
    // {
    //     m.setColumn(i, two[i]);
    // }
    // delay(1000);
    // for (int i = 0; i < 8; i++)
    // {
    //     m.setColumn(i, one[i]);
    // }
    delay(1000);
    isReady = true;
}
void loopMatrix()
{
    if (isReady == true)
    {
        isReady = false;
        DrawCounter();
    }
}