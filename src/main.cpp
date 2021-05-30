#include "Arduino.h"
/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 8 servos, one after the other on the
  first 8 pins of the PCA9685

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815
  
  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN 0    // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 900  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2400    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servonum = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ); // Analog servos run at ~50 Hz updates

  delay(10);
}


void loop()
{
  pwm.setPWM(0, 0, 0);
  delay(1000);

  pwm.setPWM(0, 0, 900);

  delay(1000);
}

// void loop() {
//   // Drive each servo one at a time using setPWM()
//   Serial.println(servonum);
//   for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
//     pwm.setPWM(servonum, 0, pulselen);
//   }

//   delay(500);
//   for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
//     pwm.setPWM(servonum, 0, pulselen);
//   }

//   delay(500);

//   // Drive each servo one at a time using writeMicroseconds(), it's not precise due to calculation rounding!
//   // The writeMicroseconds() function is used to mimic the Arduino Servo library writeMicroseconds() behavior.
//   for (uint16_t microsec = USMIN; microsec < USMAX; microsec++) {
//     pwm.writeMicroseconds(servonum, microsec);
//   }

//   delay(500);
//   for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
//     pwm.writeMicroseconds(servonum, microsec);
//   }

//   delay(500);

//   servonum++;
//   if (servonum > 7) servonum = 0; // Testing the first 8 servo channels
// }

// // setup pin 3 for output light
// // setup pin 5 for input button
// const int buttonPin = 5; // the number of the pushbutton pin
// const int ledPin = 3;    // the number of the LED pin
// int buttonState = 0;     // variable for reading the pushbutton status

// float countDown = 0;
// int delayTime = 10;

// void setup()
// {
//   pinMode(ledPin, OUTPUT);
//   // initialize the pushbutton pin as an input:
//   pinMode(buttonPin, INPUT_PULLUP);
//   Serial.begin(9600);
// }

// void loop()
// {
//   buttonState = digitalRead(buttonPin);
//   if(buttonState == HIGH) {
//   } else {
//   }
//   if (countDown <= 0)
//   {
//     if (buttonState == LOW)
//     {
//       digitalWrite(ledPin, LOW);
//       countDown = 3;
//     } else
//     {
//       digitalWrite(ledPin, HIGH);
//     }
//   }
//   else
//   {
//     countDown -= 1000 / delayTime;
//     delay(delayTime);
//   }
// }