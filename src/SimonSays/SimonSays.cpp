#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
const int buttonPin = 5; // the number of the pushbutton pin
const int ledPin = 3;    // the number of the LED pin
int buttonState = 0;     // variable for reading the pushbutton status

float countDown = 0;
int delayTime = 10;

struct Button
{
  int btnState;   // = 0;
  int ledAddress; // = 3; // use pin address?
  int buttonPin;  // = 5;
  float timeCountdown;
};

struct Button buttons[4] = {
    {0, 0x40, 0, 0},
    {0, 0x41, 1, 0},
    {0, 0x42, 2, 0},
    {0, 0x43, 3, 0}};

void setupSimonSays()
{
  for (int i = 0; i < 4; i++)
  {
    pinMode(buttons[i].buttonPin, INPUT_PULLUP);
  }
  pinMode(ledPin, OUTPUT); // setup
}

void loopSimonSays(Adafruit_PWMServoDriver pwm, int delayTimeMs)
{
  for (int i = 0; i < 4; i++)
  {
    buttons[i].btnState = digitalRead(buttons[i].buttonPin);
    if (buttons[i].btnState == HIGH)
    {
      pwm.setPWM(buttons[i].ledAddress, 0, 900);
    }
    else
    {
      if (buttons[i].timeCountdown <= 0)
      {
        pwm.setPWM(buttons[i].ledAddress, 0, 0);
      }
      else
      {
        buttons[i].timeCountdown -= delayTimeMs;
      }
    }
  }

  // if (buttonState == HIGH)
  // {

  // }
  // else
  // {
  // }
  // if (countDown <= 0)
  // {
  //   if (buttonState == LOW)
  //   {
  //     digitalWrite(ledPin, LOW);
  //     countDown = 3;
  //   }
  //   else
  //   {
  //     digitalWrite(ledPin, HIGH);
  //   }
  // }
  // else
  // {
  //   countDown -= 1000 / delayTime;
  // }
}