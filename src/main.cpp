#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SimonSays/SimonSays.h>
#include <LightedButtons/LightedButtons.h>
#include <Vibrator/Vibrator.h>
#include <Matrix/Matrix.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
int delayTimeMs = 100;

void setup()
{
  Serial.begin(9600);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ); // Analog servos run at ~50 Hz updates

  setupSimonSays();
  setupLightedButtons();
  setupVibrator();
  setupMatrix();
  delay(10);
}

void loop()
{
  // loopSimonSays(pwm, delayTimeMs);
  // loopLightedButtons(pwm, delayTimeMs);
  // loopVibrator(pwm, delayTimeMs);
  loopMatrix();
  // delay(100);
}