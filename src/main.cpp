#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SimonSays/SimonSays.h>
#include <LightedButtons/LightedButtons.h>
#include <Vibrator/Vibrator.h>
#include <Matrix/Matrix.h>
#include <UltraSonicDistance/UltraSonicDistance.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
int delayTimeMs = 10;
bool renderSuccess = false;

void Success()
{
  // Serial.println("Success");
  renderSuccess = true;
}

void setup()
{
  Serial.begin(9600);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ); // Analog servos run at ~50 Hz updates
  ultraSetup(delayTimeMs);
  setupSimonSays(Success);
  // setupLightedButtons();
  // setupVibrator();
  setupMatrix();
  delay(10);
}


void loop()
{
  ultraLoop();
  // loopSimonSays(pwm, delayTimeMs);
  // loopLightedButtons(pwm, delayTimeMs);
  // loopVibrator(pwm, delayTimeMs);
  if (renderSuccess)
  {
    // loopMatrix(true);
    renderSuccess = false;
  }
  else
  {
    // loopMatrix(false);
  }
  delay(delayTimeMs);
}