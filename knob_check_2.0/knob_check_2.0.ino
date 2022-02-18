#include <SoftwareSerial.h>

double knob = 0.0;
int value = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  knob = analogRead(value);
  Serial.print(knob);
}
