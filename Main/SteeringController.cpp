#include "SteeringController.h"
#include "Arduino.h"
#include<Servo.h>


SteeringController::SteeringController()
{
  steeringServo.attach(servoPin);
}
void SteeringController::changeSteeringAngle(int angle)
{
  steeringServo.write(angle);
}
