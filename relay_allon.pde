void setup()   
{
  // all relays are off on startup
  int pin;

  for (pin = 1; pin < 6; pin++) 
  {
    digitalWrite(pin, 0);
    pinMode(pin, 0);   
  }
}


void loop()   
{
  // just start them once up
  int pin;

  for (pin = 1; pin < 6; pin++) 
  {
    digitalWrite(pin, 1);
  }
}
