#include <Arduino.h>
#include <DNSServer.h>
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#else
#include <WiFi.h>
#include <WebServer.h>
#endif
#include <WiFiManager.h>

#if defined(ESP32)
#define LED_BUILTIN 1
#endif
#define LOOP_INTERVAL 500

byte ledState = LOW;
unsigned long previousMillis = 0;

void setup() {
  WiFiManager wifiManager;

  pinMode(LED_BUILTIN, OUTPUT);
  wifiManager.autoConnect();
}

void loop() {
  unsigned long currentMillis;

  currentMillis = millis();
  if (currentMillis - previousMillis >= LOOP_INTERVAL) {
    previousMillis = currentMillis;
    ledState = ledState == LOW ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }
}