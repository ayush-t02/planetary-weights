#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd = LiquidCrsytal(2, 3, 4, 5, 6, 7);
SoftwareSerial knob_input(10, 11);
double weight = 62.78;
double knob;

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
    knob_input.begin(9600);
}

void loop()
{
    if (knob_input.available() > 0)
    {
        knob = knob_input.read();

        if ((knob > 0) && (knob <= 300))
        {
            lcd.setCursor(0, 0);
            lcd.digitalWrite("Sun: ");
            lcd.setCursor(0, 1);
            lcd.digitalWrite(weight * 27.01);
        }
        if ((knob > 300) && (knob <= 600))
        {
            lcd.setCursor(0, 0);
            lcd.digitalWrite("Mercury: ");
            lcd.setCursor(0, 1);
            lcd.digitalWrite(weight * 0.38);
        }
        if ((knob > 600) && (knob <= 900))
        {
            lcd.setCursor(0, 0);
            lcd.digitalWrite("Moon: ");
            lcd.setCursor(0, 1);
            lcd.digitalWrite(weight * 0.166);
        }
        if ((knob > 900) && (knob <= 1200))
        {
            lcd.setCursor(0, 0);
            lcd.digitalWrite("Jupiter: ");
            lcd.setCursor(0, 1);
            lcd.digitalWrite(weight * 2.34);
        }
        if ((knob > 0) && (knob <= 300))
        {
            lcd.setCursor(0, 0);
            lcd.digitalWrite("Neptune: ");
            lcd.setCursor(0, 1);
            lcd.digitalWrite(weight * 1.19);
        }
    }
}