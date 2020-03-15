#ifndef menu.h
#define menu.h

#include "Arduino.h"
#include "pins.h"
#include "functions.h"

#define START_SERIAL  Serial.begin(9600);
#define SET_TIMEOUT   Serial.setTimeout(1);
#define newline       Serial.print('\n');

void(* reset) (void) = 0;

bool menuExitFlag = false;

char getChar()
{
  //while(!Serial.available()); Removed to make this a non-blocking function
  char input = Serial.read();
  return input;
}

void buttonTest()
{
  Serial.print("Testing input switches!");
  newline;
  Serial.print("Testing the charge button...");
  newline;
  unsigned long oldTime, period = 0;
  bool success = false;
  oldTime = millis();
  while(period < 5000)
  {
    period = millis() - oldTime;
    if((period%500) == 0)
    {
      delay(1);
      Serial.print("=");
    }
    if(!digitalRead(SWITCH_CHARGE))
    {
      newline;
      Serial.print("Charge switch okay!");
      newline;
      success = true;
      break;
    }
  }
  if(!success)
  {
    newline;
    Serial.print("Charge switch not working!");
    newline;
  }

  success = false;
  Serial.print("Testing trigger button...");
  newline;
  oldTime = millis();
  period = 0;
  while(period < 5000)
  {
    period = millis() - oldTime;
    if((period%500) == 0)
    {
      delay(1);
      Serial.print("=");
    }
    if(!digitalRead(SWITCH_TRIGGER))
    {
      newline;
      Serial.print("Trigger switch okay!");
      newline;
      success = true;
      break;
    }
  }
  if(!success)
  {
    newline;
    Serial.print("Trigger switch not working!");
    newline;
  }
}

void ledTest()
{
  Serial.print("All the LEDs are supposed to glow now...");
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_RED, HIGH);
  delay(250);
  Serial.print(digitalRead(LED_GREEN));
  Serial.print(digitalRead(LED_BLUE));
  Serial.print(digitalRead(LED_RED));
  newline;
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
}

void chargerTest()
{
  int now, then;
  digitalWrite(CHARGE, HIGH);
  now = analogRead(VBG);
  delay(10);
  then = analogRead(VBG);
  if(now < then)
  {
    Serial.print("Cap charger okay!");
    newline;
  }
  else
  {
    Serial.print("Cap charger not okay!");
    newline;
  }
  
}

void selfTest()
{
  Serial.print("Self test called!");
  newline;
  buttonTest();
  ledTest();
  chargerTest();
  Serial.print("Self test finished!");
  newline;
}

void START_MENU()
{
  Serial.print("Railgun Mk.II");
  newline;
  Serial.print("> ");
  while(!menuExitFlag && digitalRead(SWITCH_CHARGE))
  {
    //Serial.print("> ");
    char option = getChar();
    if (option == 't')
    {
      Serial.print(option);
      newline;
      selfTest();
      newline;
      Serial.print("> ");
    }
    else if (option == 'e')
    {
      Serial.print(option);
      newline;
      menuExitFlag = true;
      newline;
      Serial.print("> ");
    }
    else if (option == 'r')
    {
      Serial.print(option);
      newline;
      delay(10);
      reset();
    }
    else if (option == 'c')
    {
      Serial.print("Charging!");
      newline;
      charge();
      newline;
      Serial.print("> ");
    }
    else if (option == 'f')
    {
      Serial.print("Firing!");
      newline;
      fire();
      newline;
      Serial.print("> ");
    }
  }
  menuExitFlag = false;
  digitalWrite(LED_BLUE, LOW);
  Serial.print("Resuming normal operation!");
  delay(500);
}

#endif
