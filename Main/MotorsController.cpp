#include "Arduino.h"
#include "MotorsController.h"
#include "MotorPinsControl.h"


MotorsController::MotorsController()
{
  frontMotor = new MotorPinsControl(4, 5, 12);
  backMotor = new MotorPinsControl(3, 1, 14);
  driveType = MotorsController::DriveType::allWheelDrive;
}

void MotorsController::changeDirectionToForward()
{
  frontMotor->setDirectionToForward();
  backMotor->setDirectionToForward();
}
void MotorsController::changeDirectionToBackward()
{
  frontMotor->setDirectionToBackward();
  backMotor->setDirectionToBackward();
}
void MotorsController::changeSpeed(int speed)
{
  switch (driveType)
  {
    case MotorsController::DriveType::allWheelDrive:
      frontMotor->setMotorSpeed(speed);
      backMotor->setMotorSpeed(speed);
      break;
    case MotorsController::DriveType::rearWheelDrive:
      backMotor->setMotorSpeed(speed);
      break;
    case MotorsController::DriveType::frontWheelDrive:
      frontMotor->setMotorSpeed(speed);
      break;
  }
}

void MotorsController::changeDirection(MotorsController::Direction dir)
{
  if (currentDirection != dir)
  {
    currentDirection = dir;
    switch (currentDirection)
    {
      case MotorsController::Direction::forward:
      changeDirectionToForward();
        break;
        case MotorsController::Direction::backward:
      changeDirectionToBackward();
        break;

    }
  }
}
void MotorsController::changeDriveType(MotorsController::DriveType type)
{
  if (driveType != type)
  {
    changeSpeed(0);
    driveType = type;
  }
}
