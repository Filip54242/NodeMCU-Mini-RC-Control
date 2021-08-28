
#include "Arduino.h"
#include "MotorPinsControl.h"

MotorPinsControl::MotorPinsControl(int firstPin, int secondPin, int thirdPin)
{
  firstDirectionPin = firstPin;
  secondDirectionPin = secondPin;
  speedControlPin = thirdPin;
  initMotorPins();
}

void MotorPinsControl::initMotorPins()
{
  pinMode(firstDirectionPin, OUTPUT);
  pinMode(secondDirectionPin, OUTPUT);
  pinMode(speedControlPin, OUTPUT);
}


void MotorPinsControl::setMotorSpeed(int speed)
{
  analogWrite(speedControlPin, speed);
}
void MotorPinsControl::setDirectionToForward()
{
  digitalWrite(firstDirectionPin, HIGH);
  digitalWrite(secondDirectionPin, LOW);
}
void MotorPinsControl::setDirectionToBackward()
{
  digitalWrite(firstDirectionPin, LOW);
  digitalWrite(secondDirectionPin, HIGH);
}
