//     _____ _                         _                 ____   ___   ___   ___  
//    / ____| |                       | |               |___ \ / _ \ / _ \ / _ \ 
//   | (___ | |_ _ __ ___  _ __   __ _| |__   _____  __   __) | | | | | | | | | |
//    \___ \| __| '__/ _ \| '_ \ / _` | '_ \ / _ \ \/ /  |__ <| | | | | | | | | |
//    ____) | |_| | | (_) | | | | (_| | |_) | (_) >  <   ___) | |_| | |_| | |_| |
//   |_____/ \__|_|  \___/|_| |_|\__, |_.__/ \___/_/\_\ |____/ \___/ \___/ \___/ 
//                                __/ |                                          
//                               |___/                                           

// Version 0.1 - Basique


// Passcode definition
const int code1 = 1;
const int code2 = 2;
const int code3 = 3;
const int code4 = 4;

// Variables
int codeStatus;
bool shouldError;

void setup() {
  // Setup input.ino and output.ino
  inputSetup();
  outputSetup();

  // When starting, we're asking for the passcode's first character
  codeStatus = 1;

  // Initiate Serial connection
  Serial.begin(9600);
}

void loop() {
  // Call buttonPressed and store its output as buttonVar
  // This ensure the button isn't released during the loop execution
  int buttonVar = buttonPressed();

  if(buttonVar != 0){
    if(codeStatus == 1){
      if(buttonVar == code1){
        Serial.println("Passcode authentication - Correct 1/4");
      } else {
        shouldError = true;
        Serial.println("Passcode authentication - Incorrect 1/4");
      }
    }
    if(codeStatus == 2){
      if(buttonVar == code2){
        Serial.println("Passcode authentication - Correct 2/4");
      } else {
        shouldError = true;
        Serial.println("Passcode authentication - Incorrect 2/4");
      }
    }
    if(codeStatus == 3){
      if(buttonVar == code3){
        Serial.println("Passcode authentication - Correct 3/4");
      } else {
        shouldError = true;
        Serial.println("Passcode authentication - Incorrect 3/4");
      }
    }
    if(codeStatus == 4){
      if(buttonVar == code4){
        Serial.println("Passcode authentication - Correct 4/4");
      } else {
        shouldError = true;
        Serial.println("Passcode authentication - Incorrect 4/4");
      }
    }

    if(codeStatus != 4){
      codeStatus++;
      delOutput(codeStatus-1, false);
    } else {
      if(shouldError){
        Serial.println("Passcode authentication - Failed");
        error();
        codeStatus = 1;
        shouldError = false;
      } else {
        Serial.println("Passcode authentication - Succeeded");
        delOutput(4, true);
        openSafe();
      }
    }
  }
}