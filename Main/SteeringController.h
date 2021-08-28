#ifndef SteeringController_h
#define SteeringController_h
#include "Arduino.h"
#include<Servo.h>
class SteeringController
{
  public:
    SteeringController();
    void changeSteeringAngle(int);
  private:
    int servoPin=2;
    Servo steeringServo;

};



#endif
