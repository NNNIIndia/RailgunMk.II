#ifndef pins.h
#define pins.h

#define SWITCH_CHARGE   2
#define SWITCH_TRIGGER  3
#define LED_RED         4
#define LED_GREEN       5
#define LED_BLUE        6
#define CHARGE          7
#define DONE            8
#define TRIGGER         9
#define VBG             A0

void INITIALIZE_PINS()
{
  pinMode(SWITCH_CHARGE, INPUT_PULLUP);
  pinMode(SWITCH_TRIGGER, INPUT_PULLUP);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(CHARGE, OUTPUT);
  pinMode(DONE, INPUT_PULLUP);
  pinMode(TRIGGER, OUTPUT);
  pinMode(VBG, INPUT);
}

#endif
