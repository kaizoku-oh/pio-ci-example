#include <Arduino.h>

#if defined(ESP32)
#define LED_BUILTIN 1
#endif // ESP32
#define INTERVAL 500

uint8_t ledState = LOW;
unsigned long previousMillis = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Check to see if it's time to process something in the loop; that is, if the difference
  // between the current time and last time we processed something is bigger than
  // the interval at which we want to process something.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    // Save the last time we sent data to Fireabase
    previousMillis = currentMillis;
    ledState = ledState == LOW ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }
}