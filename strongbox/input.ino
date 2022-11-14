/*
  Constants
  Define pins connected to buttons
*/
const uint8_t button1Pin = 8;
const uint8_t button2Pin = 9;
const uint8_t button3Pin = 10;
const uint8_t button4Pin = 11;

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

/*
  SETUP
  Mark all pins connected to buttons as input
*/
void inputSetup()
{
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
}

/*
  buttonPressed
  ---
  Input : Nothing
  Output: Which button is pressed
  Effect: Output which button is pressed
*/
uint8_t buttonPressed()
{
  uint8_t a;

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

  /*
    We return the number of the pressed button or 0 if no button is pressed
  */
  if (button1StatusOld == HIGH && button1Status == LOW)
  {
    a = 1;
  } else {
    a = 0;
  }
  
  if (button2StatusOld == HIGH && button2Status == LOW)
  {
    a = a + 2;
  }
  
  if (button3StatusOld == HIGH && button3Status == LOW)
  {
    a = a + 4;
  }
  
  if (button4StatusOld == HIGH && button4Status == LOW)
  {
    a = a + 8;
  }
  return a;
}


/*
  letterToNumber
  ---
  Input : A letter
  Output: The number corresponding to the letter
  Effect: Output the number corresponding to the letter
*/
int letterToNumber(char letter)
{
    return letter - 'A' + 1;
}


/*
  serialFlush
  ---
  Input : Nothing
  Output: Nothing
  Effect: Flush the serial buffer
*/
void serialFlush(){
  while (Serial.available() != 0)
  {
    int r = Serial.read();
  }
}