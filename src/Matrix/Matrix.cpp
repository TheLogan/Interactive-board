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

byte **currentAnimation;
int currentTimer;
int currentFrame;

void setupMatrix()
{
  m.init();
  m.setIntensity(0);
  currentTimer = millis();
}

void DrawFrame(byte *frame)
{
  for (int i = 0; i < 8; i++)
  {
    m.setColumn(i, frame[i]);
  }
}

void drawNextFrame(byte **animation)
{
  for (int i = 0; i < 6; i++)
  {
    DrawFrame(animation[i]);
  }
}

void loopMatrix(bool shouldRender)
{
  if (isReady == true && shouldRender)
  {
    Serial.println("is ready");
    isReady = false;
    currentAnimation = heartAnim;
    currentFrame = 0;
    currentTimer = millis() - 400;
  }
  if (currentTimer <= millis())
  {
    currentTimer = millis() + 300;
    currentFrame++;
    if (currentFrame < 7)
    {
      DrawFrame(currentAnimation[currentFrame]);
    } else {
      isReady = true;
      m.clear();
    }
  }
}