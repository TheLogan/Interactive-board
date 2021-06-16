#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

struct Button
{
  int btnState;   // = 0;
  int ledAddress; // = 3; // use pin address?
  int buttonPin;  // = 5;
  float timer;
};

struct Button buttons[4] = {
    {0, 0x40, 10, 0},
    {0, 0x41, 11, 0},
    {0, 0x42, 12, 0},
    {0, 0x43, 13, 0}};

void (*Success)(void);

void setupSimonSays(void (*functionPointer)(void))
{
  Success = functionPointer;
  for (int i = 0; i < 4; i++)
  {
    pinMode(buttons[i].buttonPin, INPUT_PULLUP);
  }
}



void loopSimonSays(Adafruit_PWMServoDriver pwm, int delayTimeMs)
{
  for (int i = 0; i < 4; i++)
  {
    buttons[i].btnState = digitalRead(buttons[i].buttonPin);
    if (buttons[i].timer <= millis())
    {
      pwm.setPWM(buttons[i].ledAddress, 0, 900);
      if (buttons[i].btnState == LOW)
      {
        pwm.setPWM(buttons[i].ledAddress, 0, 0);
        buttons[i].timer = millis() + random(1000, 5000);
        Success();
        // Tell parent that the button was pressed
      }
    }
  }
}

