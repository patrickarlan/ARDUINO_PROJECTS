#include <Arduino.h>
#define onboard 13

void setup()
{
  // put your setup code here, to run once:
  int ledPin = onboard;
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  int ledPin = onboard;
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}