#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
//SoftwareSerial knob_input(10, 11);
double weight = 90.78;
float ans;
int knob;

void setup()
{
    lcd.init();
    lcd.backlight();
    Serial.begin(9600);
//    knob_input.begin(9600);
}

void loop()
{
    while (true)
    {
        knob = analogRead(A0);
        Serial.write(knob);

        if ((knob > 0) && (knob <= 200))
        {
            ans = weight * 0.38;
            lcd.setCursor(0, 0);
            lcd.print("Mars: ");
            lcd.setCursor(0, 1);
            lcd.print(ans, 2);
            lcd.setCursor(6,0);
            lcd.print("        ");
        }
        if ((knob > 200) && (knob <= 400))
        {
            ans = weight * 1.06;
            lcd.setCursor(0, 0);
            lcd.print("Saturn: ");
            lcd.setCursor(0, 1);
            lcd.print(ans, 2);
        }
        if ((knob > 400) && (knob <= 600))
        {
            ans = weight * 0.166;
            lcd.setCursor(0, 0);
            lcd.print("Moon: ");
            lcd.setCursor(0, 1);
            lcd.print(ans, 2);
            lcd.setCursor(6,0);
            lcd.print("        ");
        }
        if ((knob > 600) && (knob <= 800))
        {
            ans = weight * 0.38;
            lcd.setCursor(0, 0);
            lcd.print("Mercury: ");
            lcd.setCursor(0, 1);
            lcd.print(ans, 2);
        }
        if ((knob > 800) && (knob <= 1000))
        {
            ans = weight * 1.19;
            lcd.setCursor(0, 0);
            lcd.print("Neptune: ");
            lcd.setCursor(0, 1);
            lcd.print(ans, 2);
        }
    }
}
