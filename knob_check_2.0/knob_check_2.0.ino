double knob = 0.0;
int value = A0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  knob = analogRead(value);
  Serial.print(knob);
}
