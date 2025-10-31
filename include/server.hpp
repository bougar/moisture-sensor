#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "config.h"

ESP8266WebServer server(80);

void handleRoot() 
{
   int percentage = moisture.getPercentage();
   const size_t CAPACITY = JSON_OBJECT_SIZE(4);
   StaticJsonDocument<CAPACITY> doc;

   doc["percentage"] = moisture.getPercentage();
   doc["rawValue"] = moisture.getRawValue();
   doc["dryValue"] = moisture.getDryValue();
   doc["wetValue"] = moisture.getWetValue();

   String jsonOutput;
   serializeJson(doc, jsonOutput);

   server.send(200, "application/json", jsonOutput);
}
 
void handleNotFound() 
{
   server.send(404, "text/plain", "Not found");
}

void InitServer()
{
   server.on("/", handleRoot);
 
   server.onNotFound(handleNotFound);
 
   server.begin();
   Serial.println("HTTP server started");
}