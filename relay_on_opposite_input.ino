
void setup()   
{
  // all relays are off on startup
  int pin;

  // relays are pins 2-6
  for (pin = 2; pin < 7; pin++) {
    digitalWrite(pin, 0);
    pinMode(pin, 0);   
  }

  // triggers are pins 8-12
  for (pin = 8; pin < 13; pin++) {
    pinMode(pin, INPUT);
  }
}

void loop()   
{
  int pin;
  int trigger;

  // check each relay trigger
  // a trigger that is on starts the pin opposite
  for (trigger = 8; trigger < 13; trigger++) {
    pin = trigger - 6;
    if ( digitalRead(trigger) == 1 ) {
      digitalWrite(pin, 1);
    } else {
      digitalWrite(pin, 0);
    }
  }
}
