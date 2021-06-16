#include <Arduino.h>
#include <time.h>
#include <iostream>
#include <vector>

const int buzzer = 9;
const int trigPin = 11;
const int echoPin = 10;
long duration;
int distanceCm;

std::vector<int> myStack;
void ultraSetup()
{
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myStack.insert(180, 0);
}

void ultraLoop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;

  // distanceBuffer.

  // tone(buzzer, 1000); // Send 1KHz sound signal...
  // delay(1000);        // ...for 1 sec
  // noTone(buzzer);     // Stop sound...
  // delay(1000);        // ...for 1sec

  // tone(buzzer, distanceCm * 10);
  if (myStack.size() > 10)
  {
    myStack.pop_back();
  }
  if(distanceCm < 200) {
    myStack.insert(0, distanceCm);
  }

  int total = 0;
  for (size_t i = 0; i < myStack.size(); i++)
  {
    total = +myStack[i];
  }

  int median = total/myStack.size();

  if (median < 30)
  {
    // tone(buzzer, 100);
    for (uint8_t i = 200; i > 180; i--)
    {
      tone(buzzer, i);
      delay(0.1);
    }
  }
  else
  {
    noTone(buzzer);
  }

  Serial.println(distanceCm);
}

// void chirp()
// { // Bird chirp
// for (uint8_t i = 200; i > 180; i--)
//   playTone(i, 9);
// }

// void playTone(uint16_t tone1, uint16_t duration) {
//   if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
//   for (long i = 0; i < duration * 1000L; i += tone1 * 2) {
//      digitalWrite(SPEAKER, HIGH);
//      delayMicroseconds(tone1);
//      digitalWrite(SPEAKER, LOW);
//      delayMicroseconds(tone1);
//   }
// }