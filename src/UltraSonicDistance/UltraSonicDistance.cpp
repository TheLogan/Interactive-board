#include <Arduino.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>

const int buzzer = 9;
const int trigPin = 11;
const int echoPin = 10;
long duration;

std::vector<int> myStack = {180};

int currentTone = 0;
int frames[6] = {10, 12, 1, 1, 1, 1};

int getDistance();
int getMedianPoint(int distanceInCm);
void PlayNextFrame();
int fixedDelay = 0;

void ultraSetup(int globalDelay)
{
  fixedDelay = globalDelay;
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myStack.insert(0, 180);
}

void ultraLoop()
{
  if (currentTone > 0)
  {
    PlayNextFrame();
  }
  else
  {
    noTone(buzzer);

    int distanceInCm = getDistance();
    int median = getMedianPoint(distanceInCm);
    
    std::string myStr = "";
    printf("player %d", median);

    Serial.println("median: " + std::to_string(median) + ", ends here");

    if (median > 30)
    {
      currentTone = 1; //This will start the sound from the next frame onward
    }
    Serial.println(distanceInCm);
  }
}

int getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

int getMedianPoint(int distanceInCm)
{ //FIXME: this doesn't work yet
  Serial.println("stackSize: " + myStack.size());
  if (myStack.size() > 10)
  {
    myStack.pop_back();
  }
  if (distanceInCm < 200)
  {
    myStack.insert(0, distanceInCm);
  }

  int total = 0;
  for (size_t i = 0; i < myStack.size(); i++)
  {
    total = +myStack[i];
  }
  return total / myStack.size();
}

void PlayNextFrame()
{
  tone(buzzer, frames[currentTone], fixedDelay);
  currentTone++;
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