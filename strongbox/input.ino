/*
  Constants
  Define pins connected to buttons
*/
const uint8_t button1Pin = 13;
const uint8_t button2Pin = 12;
const uint8_t button3Pin = 11;
const uint8_t button4Pin = 10;
const uint8_t button5Pin = 9;
const uint8_t button6Pin = 8;
const uint8_t button7Pin = A5;
const uint8_t button8Pin = A4;
const uint8_t button9Pin = A3;
const uint8_t button0Pin = A2;
const uint8_t buttonVPin = A1;

/* 
  Globals declaration
*/
bool button1Status;
bool button1StatusOld;
bool button2Status;
bool button2StatusOld;
bool button3Status;
bool button3StatusOld;
bool button4Status;
bool button4StatusOld;
bool button5Status;
bool button5StatusOld;
bool button6Status;
bool button6StatusOld;
bool button7Status;
bool button7StatusOld;
bool button8Status;
bool button8StatusOld;
bool button9Status;
bool button9StatusOld;
bool button0Status;
bool button0StatusOld;
bool buttonVStatus;
bool buttonVStatusOld;


/*
  SETUP
  Mark all pins connected to buttons as input
*/
void inputSetup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);
  pinMode(button7Pin, INPUT);
  pinMode(button8Pin, INPUT);
  pinMode(button9Pin, INPUT);
  pinMode(button0Pin, INPUT);
  pinMode(buttonVPin, INPUT);
}

/*
  buttonPressed
  Input : Nothing
  Output: Which button is pressed
  Effect: Output which button is pressed
*/
int8_t buttonPressed() {
  /*
    Here, we define 2 variables:
    - buttonXStatus which is the current status of the button (pressed or not)
    - buttonXStatusOld which is the status of the button during the last function execution
    By comparing the two we can detect when a button is pressed
  */

  button1StatusOld = button1Status;
  button1Status = digitalRead(button1Pin);
  button2StatusOld = button2Status;
  button2Status = digitalRead(button2Pin);
  button3StatusOld = button3Status;
  button3Status = digitalRead(button3Pin);
  button4StatusOld = button4Status;
  button4Status = digitalRead(button4Pin);
  button5StatusOld = button5Status;
  button5Status = digitalRead(button5Pin);
  button6StatusOld = button6Status;
  button6Status = digitalRead(button6Pin);
  button7StatusOld = button7Status;
  button7Status = digitalRead(button7Pin);
  button8StatusOld = button8Status;
  button8Status = digitalRead(button8Pin);
  button9StatusOld = button9Status;
  button9Status = digitalRead(button9Pin);
  button0StatusOld = button0Status;
  button0Status = digitalRead(button0Pin);
  buttonVStatusOld = buttonVStatus;
  buttonVStatus = digitalRead(buttonVPin);

  /*
    We return the number of the pressed button or 0 if no button is pressed
  */
  if (button1StatusOld == HIGH && button1Status == LOW) {
    return 1;
  } else if (button2StatusOld == HIGH && button2Status == LOW) {
    return 2;
  } else if (button3StatusOld == HIGH && button3Status == LOW) {
    return 3;
  } else if (button4StatusOld == HIGH && button4Status == LOW) {
    return 4;
  } else if (button5StatusOld == HIGH && button5Status == LOW) {
    return 5;
  } else if (button6StatusOld == HIGH && button6Status == LOW) {
    return 6;
  } else if (button7StatusOld == HIGH && button7Status == LOW) {
    return 7;
  } else if (button8StatusOld == HIGH && button8Status == LOW) {
    return 8;
  } else if (button9StatusOld == HIGH && button9Status == LOW) {
    return 9;
  } else if (button0StatusOld == HIGH && button0Status == LOW) {
    return 0;
  } else if (buttonVStatusOld == HIGH && buttonVStatus == LOW) {
    return -2;
  } else {
    return -1;
  }
}