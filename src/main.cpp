#include <Arduino.h>

#define LED_BUILTIN 1
#define BLINK_DELAY 1000

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(BLINK_DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(BLINK_DELAY)
}