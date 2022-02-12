#include <SoftwareSerial.h>
#include <SPI.h>
#include <DMD.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

#define ROW 1
#define COLUMN 1
#define FONT Arial_Black_16
DMD led(ROW, COLUMN);

double weight = 110.78;
float ans;
int knob, fans;

void scan_module()
{
  led.scanDisplayBySPI();
}

void setup() {
    Serial.begin(9600);
    led.clearScreen( true );
}

void loop() {
 while (true)
    {
        knob = analogRead(A0);
        Serial.write(knob);

        led.selectFont(SystemFont5x7);
        led.drawString( 2,9, "world,", 5, GRAPHICS_NORMAL );

//        if ((knob > 0) && (knob <= 200))
//        {
//            ans = weight * 0.38;
//            led.selectFont(SystemFont5x7);
//            led.drawChar(  5,  5, 'SUN: ', GRAPHICS_NORMAL );
// 
//
//        }
    }
}
