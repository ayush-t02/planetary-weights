// Insert file Library
#include <SPI.h>
#include <DMD2.h>
#include <fonts/Arial_Black_16.h>
#include <SoftwareSerial.h>

// Number of P10 panels used X, Y
SoftDMD dmd(1,1);
// Set Box (dmd, x, y, Height, Width)
DMD_TextBox box(dmd, 2, 1, 16, 6); 
// Set Box (dmd, x, y, Height, Width)
DMD_TextBox box1(dmd, 4, 3, 16, 6);

double knob, load;

// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial weight(10, 11); 

// software serial #2: RX = digital pin 8, TX = digital pin 9
// on the Mega, use other pins instead, since 8 and 9 don't work on the Mega
SoftwareSerial potentiometer(8, 9);

void setup() {
  dmd.setBrightness(10); // Set brightness 0 - 255 
  dmd.selectFont(Arial_Black_16); // Font used
  dmd.begin();     // Start DMD
  Serial.begin(9600); 
  weight.begin(9600);
  potentiometer.begin(9600);
}

void loop() {
  box.print("VIT"); // Display TEXT SFE

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
//      lcd.setCursor(0, 0);
//      lcd.print("Sun: ");
//      lcd.setCursor(0, 1);
//      lcd.print(weight * 27.01);
      dmd.drawString(2,1,"Sun: ");
      dmd.drawString(4,3,String(weight * 27.01));
    }
    if ((knob > 300) && (knob <= 600))
    {
//      lcd.setCursor(0, 0);
//      lcd.print("Mercury: ");
//      lcd.setCursor(0, 1);
//      lcd.print(weight * 0.38);
      dmd.drawString(2,1,"Mercury: ");
      dmd.drawString(4,3,String(weight * 0.38));
    }
    if ((knob > 600) && (knob <= 900))
    {
//      lcd.setCursor(0, 0);
//      lcd.print("Moon: ");
//      lcd.setCursor(0, 1);
//      lcd.print(weight * 0.166);
      dmd.drawString(2,1,"Moon: ");
      dmd.drawString(4,3,String(weight * 0.166));
    }
    if ((knob > 900) && (knob <= 1200))
    {
//      lcd.setCursor(0, 0);
//      lcd.print("Jupiter: ");
//      lcd.setCursor(0, 1);
//      lcd.print(weight * 2.34);
      dmd.drawString(2,1,"Jupiter: ");
      dmd.drawString(4,3,String(weight * 2.34));
    }
    if ((knob > 1200) && (knob <= 1500))
    {
//      lcd.setCursor(0, 0);
//      lcd.print("Neptune: ");
//      lcd.setCursor(0, 1);
//      lcd.print(weight * 1.19);
      dmd.drawString(2,1,"Neptune: ");
      dmd.drawString(4,3,String(weight * 1.19));
    }
  }
}
