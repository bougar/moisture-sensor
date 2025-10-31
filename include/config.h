#ifndef CONFIG_H
#define CONFIG_H

#include <ESP8266WiFi.h>
#include "Moisture.cpp"

const int DRY_VALUE = 800;
const int WET_VALUE = 315;

const char* ssid     = "QuePasariaSi";
const char* password = "Zapato1?";
const char* hostname = "ESP8266_1";

IPAddress ip(192, 168, 137, 207);
IPAddress gateway(192, 168, 137, 207);
IPAddress subnet(255, 255, 255, 0);

Moisture moisture(DRY_VALUE, WET_VALUE);

#endif