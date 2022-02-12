#include <SPI.h>
#include <DMD.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#define ROW 1
#define COLUMN 1
#define FONT Arial_Black_16
DMD led(ROW, COLUMN);

void setup() {
  led.clearScreen( true );

}

void loop() {
  led.selectFont(SystemFont5x7);
  led.drawString( 2,9, "world,", 5, GRAPHICS_NORMAL );

}
