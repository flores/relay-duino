void setup()   
{
  // all relays are off on startup
  int pin;

  for (pin = 0; pin < 6; pin++) 
  {
    digitalWrite(pin, 0);
    pinMode(pin, 0);   
  }
}


void loop()   
{
  // just start them once up
  int pin;

  for (pin = 0; pin < 6; pin++) 
  {
    digitalWrite(pin, 1);
  }

  int hours;
  int wait;

  hours = 8;
  wait = 1000 * 60 * hours;

  delay(wait);

  for (pin = 0; pin < 6; pin++)
  {
   digitalWrite(pin, 0);
  }

}
