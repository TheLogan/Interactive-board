#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#define SERVOMIN 0    // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 900  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2400    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

void setupLightedButtons()
{
  // Setup 5-10 buttons with
}

void loopLightedButtons(Adafruit_PWMServoDriver pwm, int delayTimeMs)
{
  pwm.setPWM(0, 0, 0);
  delay(1000);

  pwm.setPWM(0, 0, 900);

  delay(1000);
}