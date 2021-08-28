#ifndef MotorsController_h
#define MotorsController_h
#include "Arduino.h"
#include "MotorPinsControl.h"

class MotorsController
{
  public:
    enum DriveType
    {
      frontWheelDrive, rearWheelDrive, allWheelDrive
    };
    enum Direction
    {
      forward = 1, backward = -1
    };
    MotorsController();
    void changeDirectionToForward();
    void changeDirectionToBackward();
    void changeSpeed(int);
    void changeDriveType(DriveType);
    void changeDirection(Direction);
  private:
    void initController();
    MotorPinsControl* frontMotor;
    MotorPinsControl* backMotor;
    DriveType driveType;
    Direction currentDirection;
};
#endif
