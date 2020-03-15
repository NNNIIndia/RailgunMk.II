#ifndef functions.h
#define functions.h

#include "Arduino.h"
#include "menu.h"
#include "pins.h"

void fire()
{
  while(digitalRead(SWITCH_TRIGGER));
  digitalWrite(LED_RED, LOW);
}

void charge()
{
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(CHARGE, HIGH);
  while(digitalRead(DONE));
  digitalWrite(CHARGE, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, HIGH);
}

#endif
