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

int val = 0;
byte btnNum = 255;
byte prevBtnNum = 255;

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  val = analogRead(analogPin);
  if (val <= 992) {
    // SOME button is pressed
    delay(20); // Debounce button
    val = analogRead(analogPin);  // Re-read the pin now that button's been debounced
    if (val > 992) { return; }  // Make sure value is still a button press
    
    // Determine which button was pressed

    if (val > 929 && val <= 992) { btnNum = 15; }
    if (val > 864 && val <= 929) { btnNum = 14; }
    if (val > 798 && val <= 864) { btnNum = 13; }
    if (val > 733 && val <= 798) { btnNum = 12; }
    if (val > 671 && val <= 733) { btnNum = 11; }
    if (val > 608 && val <= 671) { btnNum = 10; }
    if (val > 543 && val <= 608) { btnNum = 9; }
    if (val > 479 && val <= 543) { btnNum = 8; }
    if (val > 413 && val <= 479) { btnNum = 7; }
    if (val > 348 && val <= 413) { btnNum = 6; }
    if (val > 285 && val <= 348) { btnNum = 5; }
    if (val > 221 && val <= 285) { btnNum = 4; }
    if (val > 157 && val <= 221) { btnNum = 3; }
    if (val > 92 && val <= 157) { btnNum = 2; }
    if (val > 30 && val <= 92) { btnNum = 1; }
    if (val >= 0 && val <= 30) { btnNum = 0; }

    Serial.print(val); Serial.print(" - Btn #"); Serial.println(btnNum);
    sendKeyboardShortcut(btnNum);
    
    delay(500);
    Serial.println("-----");
  }
  
  
  /*
  val = analogRead(analogPin);
  
  if (val <= 992) {
    // SOME button is pressed
    //if (btnNum != prevBtnNum) {
      delay(100); // Debounce button
      val = analogRead(analogPin);  // Re-read the pin now that button's been debounced
    //}

    // Determine which button was pressed
    if (val > 929 && val <= 992) { btnNum = 15; }
    if (val > 864 && val <= 929) { btnNum = 14; }
    if (val > 798 && val <= 864) { btnNum = 13; }
    if (val > 733 && val <= 798) { btnNum = 12; }
    if (val > 671 && val <= 733) { btnNum = 11; }
    if (val > 608 && val <= 671) { btnNum = 10; }
    if (val > 543 && val <= 608) { btnNum = 9; }
    if (val > 479 && val <= 543) { btnNum = 8; }
    if (val > 413 && val <= 479) { btnNum = 7; }
    if (val > 348 && val <= 413) { btnNum = 6; }
    if (val > 285 && val <= 348) { btnNum = 5; }
    if (val > 221 && val <= 285) { btnNum = 4; }
    if (val > 157 && val <= 221) { btnNum = 3; }
    if (val > 92 && val <= 157) { btnNum = 2; }
    if (val > 30 && val <= 92) { btnNum = 1; }
    if (val >= 0 && val <= 30) { btnNum = 0; }
    
    if (btnNum != prevBtnNum && prevBtnNum == 255) {  // (&& prevBtnNum==255) to debouce 'release' too.
      //delay(100);  // Debounce button press
      //val = analogRead(analogPin);  // Re-read the pin, now that button has been debounced.
    
      Serial.print(val); Serial.print(" - Btn #"); Serial.println(btnNum);
      sendKeyboardShortcut(btnNum);
      prevBtnNum = btnNum;
      
      //delay(200);  // Debounce button press
    }
    
    //delay(1000);
  } else {
    // No Button is being pressed, so reset prevBtnNum
    prevBtnNum = 255;  // None
  }*/
  
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