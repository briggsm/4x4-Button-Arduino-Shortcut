// This is for 4x4 Button Keypad ("analog")

#include "Keyboard.h"

char cmdKey = KEY_LEFT_GUI;
char altKey = KEY_LEFT_ALT;
char ctrlKey = KEY_LEFT_CTRL;
char shiftKey = KEY_LEFT_SHIFT;
char upKey = KEY_UP_ARROW;
char downKey = KEY_DOWN_ARROW;
char leftKey = KEY_LEFT_ARROW;
char rightKey = KEY_RIGHT_ARROW;

int analogPin = A3;

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  int val = analogRead(analogPin);
  if (val <= 970) {
    delay(20); // Debounce button

    byte firstReadingBtn = getBtnNum(val);
    
    // Make sure we have the same value at least 29 out of 30 times.
    byte sameBtnCtr = 0;
    for (byte i = 0; i < 30; i++) {
      val = analogRead(analogPin);
      if (firstReadingBtn == getBtnNum(val)) {
        sameBtnCtr++;
      }
    }

    if (sameBtnCtr >= 29) {
      Serial.print("[");
      Serial.print(sameBtnCtr);
      Serial.print("] ");
      Serial.print(val); Serial.print(" - Btn #"); Serial.println(firstReadingBtn);
      sendKeyboardShortcut(firstReadingBtn);
      delay(250);  // in case there loose wire fluctuations, this will give me time to get finger off button, before it rapidly fires.

      // Just stay here until button is released.
      while (val <= 970) {
        delay(1);
        val = analogRead(analogPin);
      }
    } else {
      Serial.print("[");
      Serial.print(sameBtnCtr);
      Serial.print("] xxxxx firstReadingBtn: ");
      Serial.println(firstReadingBtn);
    }
  }
}

byte getBtnNum(int val) {
  byte b = 255;
  
  if (val > 929 && val <= 970) { b = 15; }
  if (val > 864 && val <= 929) { b = 14; }
  if (val > 798 && val <= 864) { b = 13; }
  if (val > 733 && val <= 798) { b = 12; }
  if (val > 671 && val <= 733) { b = 11; }
  if (val > 608 && val <= 671) { b = 10; }
  if (val > 543 && val <= 608) { b = 9; }
  if (val > 479 && val <= 543) { b = 8; }
  if (val > 413 && val <= 479) { b = 7; }
  if (val > 348 && val <= 413) { b = 6; }
  if (val > 285 && val <= 348) { b = 5; }
  if (val > 221 && val <= 285) { b = 4; }
  if (val > 157 && val <= 221) { b = 3; }
  if (val > 92 && val <= 157) { b = 2; }
  if (val > 30 && val <= 92) { b = 1; }
  if (val >= 0 && val <= 30) { b = 0; }
  
  return b;
}

void sendKeyboardShortcut(byte btnNum) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  
  switch (btnNum) {
    case 0:
      Keyboard.write('y');
      break;
      
    case 1:
      Keyboard.write('u');
      break;
    case 2:
      Keyboard.write('i');
      break;
    case 3:
      Keyboard.write('o');
      break;
    case 4:
      Keyboard.write('h');
      break;
    case 5:
      Keyboard.write('j');
      break;
    case 6:
      Keyboard.write('k');
      break;
    case 7:
      Keyboard.write('l');
      break;
    case 8:
      Keyboard.write('n');
      break;
    case 9:
      Keyboard.write('m');
      break;
    case 10:
      Keyboard.write(',');
      break;
    case 11:
      Keyboard.write('.');
      break;
    case 12:
      Keyboard.write('w');
      break;
    case 13:
      Keyboard.write('e');
      break;
    case 14:
      Keyboard.write('t');
      break;
    case 15:
      //Keyboard.releaseAll();
      //Keyboard.write('p');
      Keyboard.write('p');
      break;
  }
  
  Keyboard.releaseAll();
}