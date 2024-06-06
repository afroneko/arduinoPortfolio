#include <Servo.h>

//Initialize the servomotor
Servo myServo;
int positie;
const int btnPin1 = 12;
const int btnPin2 = 5;

void setup() {
  myServo.attach(3);
  pinMode(btnPin1, INPUT);
  pinMode(btnPin2, INPUT);
}

//Method for reading the input of the buttons
int readButton(int pin) {
    int state = digitalRead(pin);
    delay(50); // a debounce delay
    if(state == digitalRead(pin)) {
      return state;
    }
    return LOW;
  }

void loop() {
  int fast = readButton(btnPin2);
  int slow = readButton(btnPin1);

//int range will be used in the switch statement so the three different options can be worked out
  int range;
  if (fast == HIGH && slow == LOW) {
    range = 1;
  } else if (fast == LOW && slow == HIGH) {
    range = 2;
  } else if (fast == HIGH && slow == HIGH) {
    range = 3;
  } else {
    range = -1;
  }
 
 //A switch statement with the three different cases
  switch (range) {
  case 1:
    for(positie = 0; positie <= 120; positie +=1) {
      myServo.write(positie);
      delay(41); //De delay is per stap, in totaal is dit ongeveer 5 seconden
    }
    for(positie = 120; positie >= 0; positie-= 1) {
      myServo.write(positie);
      delay(41);
    }
    break;
  case 2:
    for(positie = 0; positie <= 120; positie +=1) {
      myServo.write(positie);
      delay(4); //De delay is per stap, in totaal is dit ongeveer 0,5 seconden
    }
    for(positie = 120; positie >= 0; positie-= 1) {
      myServo.write(positie);
      delay(4);
    }
    break;
  case 3:
    for(positie = 0; positie <= 120; positie +=1) {
      myServo.write(positie);
      delay(41);
    }
    delay(2000);
    for(positie = 120; positie >= 0; positie-= 1) {
      myServo.write(positie);
      delay(4);
    }
    break;
  }


 
}
