#pragma once
#include <Arduino.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
#include <SPIFFS.h>
char ssid[16];
char pass[16];
void readFile();
const char* getSSID();
const char* getPASS();
void setSSID(const char*);
void setPASS(const char*);

void littleFSBegin() {
  SPIFFS.begin();
  readFile();
  readFile();
}
const char* getSSID() { return (const char*)ssid; }
void setSSID(const char* _ssid) { strcpy(ssid, _ssid); }
const char* getPASS() { return (const char*)pass; }
void setPASS(const char* _pass) { strcpy(pass, _pass); }
void readFile() {
  StaticJsonDocument<255> doc;
  Serial.setTimeout(1000);
  File file = SPIFFS.open("/configs.json", "r");
  DeserializationError err = deserializeJson(doc, file);
  if (err) {
    Serial.println(err.c_str());
  }
  setSSID(doc["SSID"].as<const char*>());
  setPASS(doc["PASS"].as<const char*>());
  file.close();
}
