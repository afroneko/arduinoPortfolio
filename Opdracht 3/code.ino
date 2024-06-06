const int ledPin1 = 10;
const int ledPin2 = 8;
const int buttonPin = 6;
int counter;
int newBtnState;
int currentBtnState = LOW;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int input = digitalRead(buttonPin);

//Check the different states of the buttons
  if(input != currentBtnState) {
    delay(50);
  }
  if(input != newBtnState) {
    newBtnState = input;
      if(newBtnState == HIGH) {
      counter++;
      }  
  }

//When division results in 0, turn one led off and the other on. If not, reverse
  if(counter % 2 == 0) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  } else {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    }


  currentBtnState = input;
}
