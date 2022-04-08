/*
Installation:
Arduino Uno      P10 Panel
    13 ---------> S / CLK
    11 ---------> R
     9 ---------> nOE / OE
     8 ---------> L / SCLK
     7 ---------> B
     6 ---------> A
   GND ---------> GND
-----------------------------------------------------------------------------------------------------------------------------------------
Load cell installation 
 2 -> HX711 CLK
 3 -> DOUT
 5V -> VCC
 GND -> GND
*/

#include <SPI.h>       
#include <DMD.h>    
#include <TimerOne.h>  
#include <SoftwareSerial.h>
#include "Arial_black_16.h"
#include "Arial_Black_16_ISO_8859_1.h"
#include "Arial14.h"
#include "SystemFont5x7.h"
#include "HX711.h"
#include <HX711_ADC.h>
#define ROW 1
#define COLUMN 1
#define FONT Arial_Black_16
#define DISPLAYS_ACROSS 1 //-> Number of P10 panels used, side to side.
#define DISPLAYS_DOWN 1
#define calibration_factor -12.20

#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2

DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
HX711 scale(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

char *Text = "";
char chr[5];
int knob = 0; 
double load, fload;
int value = A0;

// software serial #2: RX = digital pin 8, TX = digital pin 9
// on the Mega, use other pins instead, since 8 and 9 don't work on the Mega
//SoftwareSerial potentiometer(4, 5);

void ScanDMD() 
{ 
  dmd.scanDisplayBySPI();
}

void setup(void) 
{
  Timer1.initialize(1000);          
  Timer1.attachInterrupt(ScanDMD);   
  dmd.clearScreen(true);   
  Serial.begin(9600);
  scale.set_scale(calibration_factor);
  scale.tare();
//  scale.setReverseOutput();
}

void loop(void) 
{
 while (true) 
 {
  load = scale.get_units(), 10;
  knob = analogRead(value);
  Serial.print(knob);

    if (knob == 0) 
    {
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "MOVE:    ", 8, GRAPHICS_NORMAL);
    }
    if ((knob > 0) && (knob <= 100))
    {
      fload = (-1)*(load * 27.01);
      Serial.println(fload);
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "SUN:   ", 8, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 0, 9, chr, 8, GRAPHICS_NORMAL );
      delay(5000);
    }
    if ((knob > 100) && (knob <= 200))
    {
      fload = (-1)*(load * 0.38);
      Serial.println(fload);
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "MERCURY:", 8, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 0, 9, chr, 8, GRAPHICS_NORMAL );
      delay(5000);
    }
    if ((knob > 200) && (knob <= 300))
    {
      fload = (-1)*(load * 0.166);
      Serial.println(fload);
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "MOON:   ", 8, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 0, 9, chr, 8, GRAPHICS_NORMAL );
      delay(5000);
    }
    if ((knob > 300) && (knob <= 400))
    {
      fload = (-1)*(load * 2.34);
      Serial.println(fload);
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "JUPITER:", 8, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 0, 9, chr, 8, GRAPHICS_NORMAL );
      delay(5000);
    }
    if ((knob > 400) && (knob <= 500))
    {
      fload = (-1)*(load * 1.19);
      Serial.println(fload);
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "NEPTUNE:", 8, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 0, 9, chr, 8, GRAPHICS_NORMAL );
      delay(5000);
    }
  }
}
