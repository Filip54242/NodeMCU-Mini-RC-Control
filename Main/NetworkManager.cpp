#include "NetworkManager.h"
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include<WString.h>

NetworkManager::NetworkManager()
{
  //Serial.begin(115200);
 
  //delay(1000);

  parsedMessage = new int[10];
  wifiServer = new WiFiServer(80);
  WiFi.softAP(ssid, password);
 // IPAddress myIP = WiFi.softAPIP();
  wifiServer->begin();

 //Serial.println(myIP);
}

bool NetworkManager::dataChanged()
{
  return changed;
}
int * NetworkManager::getMessageFromClient()
{
  changed = false;
  for (int i = 0; i < 10; i++)
  {
    parsedMessage[i] = 0;
  }
  parsedMessage[0] = 1;
  String message = "";
  WiFiClient client = wifiServer->available();
  if (client && client.connected()) {  
    while (client.available() > 0) {
      char c = client.read();
      if (c == ',')
      {
        changed = true;
        parsedMessage[parsedMessage[0]++] = message.toInt();
      // Serial.println(message);
        message = "";
      }

      else
      {
        message += c;
      }
    }
     client.print(returnMessage);
  }
  return parsedMessage;
}
