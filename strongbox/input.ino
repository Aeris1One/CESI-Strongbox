/*
  Constants
  Define pins connected to buttons
*/
const int button1Pin = 13;
const int button2Pin = 12;
const int button3Pin = 11;
const int button4Pin = 10;

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
void inputSetup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
}

/*
  buttonPressed
  Input : Nothing
  Output: Which button is pressed
  Effect: Output which button is pressed
*/
int buttonPressed(){
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
  if(button1StatusOld == HIGH && button1Status == LOW){
    return 1;
  }
  else if(button2StatusOld == HIGH && button2Status == LOW){
    return 2;
  }
  else if(button3StatusOld == HIGH && button3Status == LOW){
    return 3;
  }
  else if(button4StatusOld == HIGH && button4Status == LOW){
    return 4;
  }
  else{
    return 0;
  }
}