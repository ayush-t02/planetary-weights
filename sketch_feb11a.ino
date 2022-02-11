//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

//LiquidCrystal_I2C lcd(0x27, 16, 2);
//SoftwareSerial knob_input(10);
#define ROW 1
#define COLUMN 1
#define FONT Arial_Black_16
DMD led_module(ROW, COLUMN)

double weight = 110.78;
float ans;
int knob, fans;

void scan_module()
{
  led_module.scanDisplayBySPI();
}

void setup()
{
//    lcd.init();
//    lcd.backlight();
    Serial.begin(9600);
//    knob_input.begin(9600);
  Timer1.initialize(2000);
  Timer1.attachInterrupt(scan_module);
  led_module.clearScreen( true );
}

void loop()
{
    led_module.selectFont(FONT);
    while (true)
    {
        knob = analogRead(A0);
        Serial.write(knob);

        if ((knob > 0) && (knob <= 200))
        {
            ans = weight * 0.38;
            led_module.setCursor(0, 0);
            led_module.display("Sun: ");
            lcd.setCursor(0, 1);
            fans = (int)(ans);
            
            if (fans < 100) {
              led_module.display(ans, 2);
              lcd.setCursor(5, 1);
              led_module.display("  ");
            } else {
              led_module.display(fans);
            }
            lcd.setCursor(6,0);
            led_module.display("        ");
        }
        if ((knob > 200) && (knob <= 400))
        {
            ans = weight * 1.06;
            lcd.setCursor(0, 0);
            led_module.display("Saturn: ");
            lcd.setCursor(0, 1);
            fans = (int)(ans);
            
            if (fans < 100) {
              led_module.display(ans, 2);
              lcd.setCursor(5, 1);
              led_module.display("  ");
            } else {
              led_module.display(fans);
            }
            lcd.setCursor(6,0);
            led_module.display("        ");
        }
        
        if ((knob > 400) && (knob <= 600))
        {
            ans = weight * 0.166;
            lcd.setCursor(0, 0);
            led_module.display("Moon: ");
            lcd.setCursor(0, 1);
            fans = (int)(ans);
            
            if (fans < 100) {
              led_module.display(ans, 2);
              lcd.setCursor(5, 1);
              led_module.display("  ");
            } else {
              led_module.display(fans);
            }
            lcd.setCursor(6,0);
            led_module.display("        ");
        }
        if ((knob > 600) && (knob <= 800))
        {
            ans = weight * 0.38;
            lcd.setCursor(0, 0);
            lcd.print("Mercury: ");
            lcd.setCursor(0, 1);
            fans = (int)(ans);

            if (fans < 100) {
              lcd.print(ans, 2);
              lcd.setCursor(5, 1);
              lcd.print("  ");
            } else {
              lcd.print(fans);
            }
            lcd.setCursor(3,1);
            lcd.print("  ");
        }
        
        if ((knob > 800) && (knob <= 1000))
        {
            ans = weight * 1.19;
            lcd.setCursor(0, 0);
            lcd.print("Neptune: ");
            lcd.setCursor(0, 1);
            fans = (int)(ans);

            if (fans < 100) {
              lcd.print(ans, 2);
              lcd.setCursor(5, 1);
              lcd.print("  ");
            } else {
              lcd.print(fans);
            }
            lcd.setCursor(3,1);
            lcd.print("  ");
        }
    }
}
