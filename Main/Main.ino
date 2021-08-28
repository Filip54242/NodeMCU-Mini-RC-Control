
#include "MotorsController.h"
#include "SteeringController.h"
#include "NetworkManager.h"

MotorsController *motorControl;
SteeringController *steeringControl;
NetworkManager *networkManager;

void setup() {
motorControl=new MotorsController();
steeringControl=new SteeringController();
networkManager=new NetworkManager();
}

void loop() {
  int* data = networkManager->getMessageFromClient();
  if (networkManager->dataChanged()) {
    motorControl->changeDirection((MotorsController::Direction)data[1]);
    motorControl->changeSpeed(data[2]);
    motorControl->changeDriveType((MotorsController::DriveType)data[3]);
    steeringControl->changeSteeringAngle(data[4]);
  }
}
