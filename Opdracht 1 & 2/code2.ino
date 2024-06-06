const int ledPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup()
{
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  forward(100);
  backward(100);
}
 //Method for turning the ledsd on left to right
  void forward(int time) {
    for(int i = 0; i<numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
        delay(time);
        digitalWrite(ledPins[i], LOW);
    }
  }  
  //Method for turning the leds on right to left             
   void backward(int time) {
    for(int i = numLeds - 1; i>0; i--) {
      digitalWrite(ledPins[i], HIGH);
        delay(time);
        digitalWrite(ledPins[i], LOW);
    }
  }
