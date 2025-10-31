#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "server.hpp"
#include "ESP8266_utils.hpp"
#include "Moisture.cpp"

const int SENSOR_PIN = A0; 

#define OLED_SDA   4
#define OLED_SCL   5

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(111520);

  ConnectWiFi_STA();
 
  InitServer();

  Wire.begin(OLED_SDA, OLED_SCL);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  
  display.setTextColor(SSD1306_WHITE);
}

void loop() {

  moisture.update(analogRead(SENSOR_PIN));

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("Moisture Level:")); 

  display.setTextSize(3);
  display.setCursor(0, 20);
  
  display.print(moisture.getPercentage());
  
  display.setTextSize(2);
  display.print("%"); 

  display.display(); 

  server.handleClient();
  
  delay(500); 
}