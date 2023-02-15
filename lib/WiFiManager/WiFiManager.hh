#pragma once
#include <Arduino.h>
#include <WiFi.h>

#include <LittleFS.hh>

void WiFiBegin() {
  Serial.println("WiFi Begin");
  WiFi.mode(WIFI_STA);
  WiFi.begin(getSSID(), getPASS());
  for (uint8_t i = 0; i < 20 && WiFi.status() != WL_CONNECTED; i++) {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("\nConnected to: %s\n", getSSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}