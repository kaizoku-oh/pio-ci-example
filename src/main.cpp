#include <Arduino.h>

#define MSG "Hello World!"
#define LOOP_DELAY 1000
#define SERIAL_BAUDRATE 115200

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
}

void loop() {
  Serial.println(MSG);
  delay(LOOP_DELAY);
}