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
*/

#include <SPI.h>       
#include <DMD.h>    
#include <TimerOne.h>  
#include <SoftwareSerial.h>
#include "Arial_black_16.h"
#include "Arial_Black_16_ISO_8859_1.h"
#include "Arial14.h"
#include "SystemFont5x7.h"

#define DISPLAYS_ACROSS 1 //-> Number of P10 panels used, side to side.
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

char *Text = "";
float s = 10.45;
char chr[5];
double knob, load, fload;

// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial weight(0, 1); 

// software serial #2: RX = digital pin 8, TX = digital pin 9
// on the Mega, use other pins instead, since 8 and 9 don't work on the Mega
SoftwareSerial potentiometer(4, 5);

void ScanDMD() { 
  dmd.scanDisplayBySPI();
}

void setup(void) {
  Timer1.initialize(1000);          
  Timer1.attachInterrupt(ScanDMD);   
  dmd.clearScreen(true);   
  Serial.begin(115200);
  weight.begin(9600);
  potentiometer.begin(9600);
}

void loop(void) {
//  dmd.selectFont(SystemFont5x7);
//  dmd.drawString(0,0, "TRY", 4, GRAPHICS_NORMAL);
//  dtostrf(s, 3, 2, chr);
//  dmd.drawString( 1, 0, chr, 4, GRAPHICS_NORMAL );
//  delay(1000);

// By default, the last intialized port is listening.
  // when you want to listen on a port, explicitly select it:
  weight.listen();
  
  Serial.println("Data from port one:");
  // while there is data coming in, read it
  // and send to the hardware serial port:
  if (weight.available() > 0)
  {
    load = weight.read();
//    Serial.write(load);
  }
  
  // Now listen on the second port
  potentiometer.listen();
  
  // potentiometer inputs
  while (potentiometer.available() > 0)
  {
    knob = potentiometer.read();
//    Serial.write(knob);

    if ((knob > 0) && (knob <= 300))
    {
      fload = load * 27.01;
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "SUN: ", 4, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 1, 0, chr, 4, GRAPHICS_NORMAL );
    }
    if ((knob > 300) && (knob <= 600))
    {
      fload = load * 0.38;
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "MERCURY: ", 4, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 1, 0, chr, 4, GRAPHICS_NORMAL );
    }
    if ((knob > 600) && (knob <= 900))
    {
      fload = load * 0.166;
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "MOON: ", 4, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 1, 0, chr, 4, GRAPHICS_NORMAL );
    }
    if ((knob > 900) && (knob <= 1200))
    {
      fload = load * 2.34;
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "JUPITER: ", 4, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 1, 0, chr, 4, GRAPHICS_NORMAL );
    }
    if ((knob > 1200) && (knob <= 1500))
    {
      fload = load * 1.19;
      dmd.selectFont(SystemFont5x7);
      dmd.drawString(0,0, "NEPTUNE: ", 4, GRAPHICS_NORMAL);
      dtostrf(fload, 3, 2, chr);
      dmd.drawString( 1, 0, chr, 4, GRAPHICS_NORMAL );
    }
  }
}
