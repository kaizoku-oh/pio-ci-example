#include <Arduino.h>
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#elif defined(ESP32)
#include <WiFi.h>
#include <WebServer.h>
#endif
#include <DNSServer.h>
#include <WiFiManager.h>

#if defined(ESP32)
#define LED_BUILTIN 1
#endif
#define LOOP_INTERVAL 500

uint8_t ledState = LOW;
uint32_t previousMillis = 0;

void setup() {
  WiFiManager wifiManager;

  pinMode(LED_BUILTIN, OUTPUT);
  wifiManager.autoConnect();
}

void loop() {
  uint32_t currentMillis;

  currentMillis = millis();
  if ((currentMillis - previousMillis) >= LOOP_INTERVAL) {
    previousMillis = currentMillis;
    ledState = (ledState == LOW) ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }
}