#include <Arduino.h>

#include <WiFiManager.hh>
#include <lib.hh>

void setup() {
  Serial.begin(115200);
  littleFSBegin();
  WiFiBegin();
  OtaBegin();
}

void loop() { OtaHandle(); }