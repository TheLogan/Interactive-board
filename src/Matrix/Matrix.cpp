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
  m.setIntensity(0);
  delay(100);
}

void DrawFrame(byte *frame)
{
  for (int i = 0; i < 8; i++)
  {
    m.setColumn(i, frame[i]);
  }
}

void DrawAnimation(byte **animation)
{
  for (int i = 0; i < 6; i++)
  {
    DrawFrame(animation[i]);
    delay(300);
  }
  isReady = true;
}

void loopMatrix()
{
  if (isReady == true)
  {
    isReady = false;
    // DrawFrame(icon_smiley);
    
    DrawAnimation(heartAnim);
  }
}