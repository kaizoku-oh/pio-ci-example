#include <Arduino.h>
#include <WiFiManager.h>

#if defined(ESP32)
#define LED_BUILTIN 1
#endif
#define LOOP_INTERVAL 500

uint8_t ledState = LOW;
uint32_t earlierMillis = 0;

void setup() {
  WiFiManager wifiManager;

  pinMode(LED_BUILTIN, OUTPUT);
  wifiManager.autoConnect();
}

void loop() {
  uint32_t nowMillis;

  nowMillis = millis();
  if((nowMillis - earlierMillis) >= LOOP_INTERVAL) {
    earlierMillis = nowMillis;
    ledState = (ledState == LOW) ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }
}