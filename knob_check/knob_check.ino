double knob;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  knob = analogRead(A0);
  if (knob == 0) {
    Serial.print("Zero");
  }
  else {
    Serial.print(knob);
  }
}
