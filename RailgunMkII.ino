//Finally, a working system! March 7th, 2020

#include "menu.h"
#include "pins.h"
#include "functions.h"

void setup() 
{
  INITIALIZE_PINS();
  START_SERIAL;
  SET_TIMEOUT;
  START_MENU();
  digitalWrite(LED_GREEN, HIGH);
}

void loop() 
{
  while(digitalRead(SWITCH_CHARGE));
  charge();
  fire();
}
