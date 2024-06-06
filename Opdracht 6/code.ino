#include <LiquidCrystal_I2C.h>
#include <Wire.h>


// Initialize the LCD screen and set the dimensions to (16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int btnStart = 12;
const int btnPause = 5;
const unsigned long debounceDelay = 50; // 50 milliseconds debounce delay
unsigned long lastDebounceTimeStart = 0;
unsigned long lastDebounceTimePause = 0;
unsigned long startTime = 0;
unsigned long lapTime = 0;
unsigned long elapsedTime = 0;
bool running = false;
bool lapRegistered = false;


void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(btnStart, INPUT);
  pinMode(btnPause, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch:");
  updateLCD();
}

//Method for reading the input of the button
int readButton(int pin) {
    int state = digitalRead(pin);
    delay(50); // a debounce delay
    if(state == digitalRead(pin)) {
      return state;
    }
    return LOW;
  }

void loop() {
  int start = readButton(btnStart);
  int pause = readButton(btnPause);
 
 //Check the states of the buttons and do something if this state is true
  if(start == HIGH && pause == LOW) {
    if(!running) {
      startStopwatch();
    } else if(millis() - lastDebounceTimeStart > 2000 && !lapRegistered) {
      registerLap();
    }
  } else if (pause == HIGH && start == LOW) {
    if(running) {
      pauseStopwatch();
    }
  } else if(start == HIGH && pause == HIGH) {
    resetStopwatch();
  }


  if (running) {
    updateElapsedTime();
    updateLCD();
  }


  // Reset lapRegistered flag if button is released
  if (digitalRead(btnStart) == HIGH) {
    lapRegistered = false;
  }
}

//Method for starting the stopwatch
void startStopwatch() {
  running = true;
  startTime = millis() - elapsedTime;
  lcd.setCursor(0, 1);
  lcd.print("Running...        ");
}

//Method for pausing the stopwatch
void pauseStopwatch() {
  running = false;
  elapsedTime = millis() - startTime;
  lcd.setCursor(0, 1);
  lcd.print("Paused           ");
}

//Method for registering the lap time
void registerLap() {
  lapTime = millis() - startTime;
  lcd.setCursor(0, 1);
  lcd.print("Lap: ");
  lcd.print(formatTime(lapTime));
  lcd.print("    ");
  lapRegistered = true;
  delay(500);  // Prevent immediate re-triggering
}

//Method for resetting the stopwatch
void resetStopwatch() {
  running = false;
  startTime = 0;
  lapTime = 0;
  elapsedTime = 0;
  lcd.setCursor(0, 1);
  lcd.print("Reset            ");
  delay(500);  // Prevent immediate re-triggering
  updateLCD();
}

//Method for updating the time
void updateElapsedTime() {
  elapsedTime = millis() - startTime;
}

//Method for updating the lCD screen
void updateLCD() {
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(formatTime(elapsedTime));
  lcd.print("    ");  // Clear any remaining characters
}


String formatTime(unsigned long time) {
  unsigned long seconds = time / 1000;
  unsigned long minutes = seconds / 60;
  seconds = seconds % 60;
  unsigned long milliseconds = time % 1000;


  char buffer[16];
  sprintf(buffer, "%02lu:%02lu.%03lu", minutes, seconds, milliseconds);
  return String(buffer);
}
