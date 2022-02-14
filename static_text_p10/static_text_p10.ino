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
#include "Arial_black_16.h"
#include "Arial_Black_16_ISO_8859_1.h"
#include "Arial14.h"
#include "SystemFont5x7.h"

#define DISPLAYS_ACROSS 1 //-> Number of P10 panels used, side to side.
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

char *Text = "";

void ScanDMD() { 
  dmd.scanDisplayBySPI();
}

void setup(void) {
  Timer1.initialize(1000);          
  Timer1.attachInterrupt(ScanDMD);   
  dmd.clearScreen(true);   
  Serial.begin(115200);
}

void loop(void) {
  dmd.selectFont(SystemFont5x7);
  dmd.drawString(0,0, "TRY", 4, GRAPHICS_NORMAL);
  dmd.drawString(0,9, "ONE", 3, GRAPHICS_NORMAL);
  delay(1000);
}
