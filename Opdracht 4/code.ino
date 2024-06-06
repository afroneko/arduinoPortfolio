const int potPin = A5;
const int ledPins[] = {13, 12, 11, 10, 9, 8};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
int potmeterWaarde = 0;

void setup() {
  for (int i = 0; i < numLeds; i++) {
 pinMode (ledPins[i], OUTPUT);
  }
 Serial.begin(9600);
}

void loop() {
 potmeterWaarde = analogRead(potPin);
 int y = map(potmeterWaarde, 0, 1023, 0, numLeds); //Turn the default into a different range with map()


 for (int i = 0; i < numLeds; i++) {
   if(i < y) {
 digitalWrite(ledPins[i], HIGH);
   }else {
     digitalWrite(ledPins[i], LOW);
   }
  }
                             
}
