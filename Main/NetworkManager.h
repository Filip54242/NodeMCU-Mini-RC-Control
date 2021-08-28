#ifndef NetworkManager_h
#define NetworkManager_h
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include<WString.h>
//#include <ESP8266WebServer.h>
class NetworkManager
{
  private:
    const char* ssid="WifiTruck";
    const char* password="gtagtagta";
    int port=80;
    WiFiServer *wifiServer;
    int * parsedMessage;
    const char * returnMessage="OK";
    bool changed;
  public:
    NetworkManager();
    int * getMessageFromClient();
    bool dataChanged();
    

};


#endif
