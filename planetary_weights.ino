#include <SoftwareSerial.h>
#define lcd 12;

int knob, load;
// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial portOne(10, 11);

// software serial #2: RX = digital pin 8, TX = digital pin 9
// on the Mega, use other pins instead, since 8 and 9 don't work on the Mega
SoftwareSerial portTwo(8, 9);

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Start each software serial port
  portOne.begin(9600);
  portTwo.begin(9600);
}

void loop()
{
  // By default, the last intialized port is listening.
  // when you want to listen on a port, explicitly select it:
  portOne.listen();
  Serial.println("Data from port one:");
  // while there is data coming in, read it
  // and send to the hardware serial port:
  while (portOne.available() > 0)
  {
    load = portOne.read();
    Serial.write(load);
    break;
  }

  // blank line to separate data from the two ports:
  Serial.println();

  // Now listen on the second port
  portTwo.listen();
  // while there is data coming in, read it
  // and send to the hardware serial port:
  Serial.println("Data from port two:");
  while (portTwo.available() > 0)
  {
    knob = portTwo.read();
    Serial.write(knob);
    break;
  }

  // blank line to separate data from the two ports:
  Serial.println();

  // potentiometer inputs
  if ((portTwo.available() > 0))
  {
    switch (knob)
    {
    case ((knob > 0) && (knob <= 300)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Mercury: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    case ((knob > 300) && (knob <= 600)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Venus: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    case ((knob > 600) && (knob <= 900)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Mars: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    case ((knob > 900) && (knob <= 1200)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Jupiter: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    case ((knob > 1200) && (knob <= 1500)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Saturn: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    case ((knob > 1200) && (knob <= 1500)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Uranus: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    case ((knob > 1200) && (knob <= 1500)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Neptune: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    case ((knob > 1200) && (knob <= 1500)):
    {
      lcd.setCursor(0, 0);
      lcd.digitalWrite("Pluto: ");
      lcd.setCursor(0, 1);
      lcd.digitalWrite(load * 1);
    }
    }
  }
}