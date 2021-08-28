#ifndef MotorPinsControl_h
#define MotorPinsControl_h
#include "Arduino.h"


class MotorPinsControl
{
  public:
    MotorPinsControl(int, int, int);
    void setMotorSpeed(int);
    void initMotorPins();
    void setDirectionToForward();
    void setDirectionToBackward();
  private:
    int firstDirectionPin;
    int secondDirectionPin;
    int speedControlPin;
};

#endif
