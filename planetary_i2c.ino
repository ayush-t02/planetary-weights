#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
double knob, load;
// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial weight(10, 11);

// software serial #2: RX = digital pin 8, TX = digital pin 9
// on the Mega, use other pins instead, since 8 and 9 don't work on the Mega
SoftwareSerial potentiometer(8, 9);

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Start each software serial port
  weight.begin(9600);
  potentiometer.begin(9600);

  // Initializing LCD.
  lcd.init();
  lcd.backlight();
}

void loop()
{
  // By default, the last intialized port is listening.
  // when you want to listen on a port, explicitly select it:
  weight.listen();
  
  Serial.println("Data from port one:");
  // while there is data coming in, read it
  // and send to the hardware serial port:
  if (weight.available() > 0)
  {
    load = weight.read();
    Serial.write(load);
  }

  // blank line to separate data from the two ports:
  Serial.println();

  // Now listen on the second port
  potentiometer.listen();

  // blank line to separate data from the two ports:
  Serial.println();

  // potentiometer inputs
  while (potentiometer.available() > 0)
  {
    knob = potentiometer.read();
    Serial.write(knob);

    if ((knob > 0) && (knob <= 300))
    {
      lcd.setCursor(0, 0);
      lcd.print("Sun: ");
      lcd.setCursor(0, 1);
      lcd.print(weight * 27.01);
    }
    if ((knob > 300) && (knob <= 600))
    {
      lcd.setCursor(0, 0);
      lcd.print("Mercury: ");
      lcd.setCursor(0, 1);
      lcd.print(weight * 0.38);
    }
    if ((knob > 600) && (knob <= 900))
    {
      lcd.setCursor(0, 0);
      lcd.print("Moon: ");
      lcd.setCursor(0, 1);
      lcd.print(weight * 0.166);
    }
    if ((knob > 900) && (knob <= 1200))
    {
      lcd.setCursor(0, 0);
      lcd.print("Jupiter: ");
      lcd.setCursor(0, 1);
      lcd.print(weight * 2.34);
    }
    if ((knob > 1200) && (knob <= 1500))
    {
      lcd.setCursor(0, 0);
      lcd.print("Neptune: ");
      lcd.setCursor(0, 1);
      lcd.print(weight * 1.19);
    }
  }
}