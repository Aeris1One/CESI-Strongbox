//     _____ _                         _                 ____   ___   ___   ___
//    / ____| |                       | |               |___ \ / _ \ / _ \ / _ \ 
//   | (___ | |_ _ __ ___  _ __   __ _| |__   _____  __   __) | | | | | | | | | |
//    \___ \| __| '__/ _ \| '_ \ / _` | '_ \ / _ \ \/ /  |__ <| | | | | | | | | |
//    ____) | |_| | | (_) | | | | (_| | |_) | (_) >  <   ___) | |_| | |_| | |_| |
//   |_____/ \__|_|  \___/|_| |_|\__, |_.__/ \___/_/\_\ |____/ \___/ \___/ \___/
//                                __/ |
//                               |___/

// Version 0.1 - Basique

// Use variable type from stdint
// https://learn.adafruit.com/deciphering-strange-arduino-code/stdint
#include <stdint.h>

// Passcode definition
const uint8_t code1 = 5;
const uint8_t code2 = 4;
const uint8_t code3 = 8;
const uint8_t code4 = 1;

// Variables
uint8_t authStatus;
bool wrongPasscode;

void setup() {
  // Setup input.ino and output.ino
  inputSetup();
  outputSetup();

  // When starting, we're asking for the passcode's first character
  authStatus = 1;
  // And no LED is on
  delOutput(0, false);

  // Initiate Serial connection
  Serial.begin(9600);
}

// FULL REWRITE NEEDED
void loop() {
  // Call buttonPressed and store its output as buttonVar
  // This ensure the button isn't released during the loop execution
  int8_t buttonVar = buttonPressed();

  /*
    auth loop
    authStatus define what is the state of authentication ongoing

    authStatus = 1 : wait for passcode first character input (blocking)
    authStatus = 2 : wait for passcode second character input (blocking)
    authStatus = 3 : wait for passcode third character input (blocking)
    authStatus = 4 : wait for passcode fourst character input (blocking)
    authStatus = 5 : verifying passcode inputs
    authStatus = 6 : wait for agent code input (blocking)
    authStatus = 7 : output encrypted random number
    authStatus = 8 : wait for decrypted number input (blocking)
    authStatus = 9 : verify number correspondance
    authStatus = 10: opening vault

    authStatus 5 and 9 are verifications, if one of them fail, revert back to 1.
  */

  if (authStatus == 1) {
    if (buttonVar > 0) {
      if (buttonVar == code1) {
        Serial.println("Passcode authentication - Correct 1/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 1/4");
      }
      authStatus++;
      delOutput(1, false);
    }
  } else if (authStatus == 2) {
    if (buttonVar > 0) {
      if (buttonVar == code2) {
        Serial.println("Passcode authentication - Correct 2/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 2/4");
      }
      authStatus++;
      delOutput(2, false);
    }
  } else if (authStatus == 3) {
    if (buttonVar > 0) {
      if (buttonVar == code3) {
        Serial.println("Passcode authentication - Correct 3/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 3/4");
      }
      authStatus++;
      delOutput(3, false);
    }
  } else if (authStatus == 4) {
    if (buttonVar > 0) {
      if (buttonVar == code4) {
        Serial.println("Passcode authentication - Correct 4/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 4/4");
      }
      authStatus++;
      delOutput(4, false);
    }
  } else if (authStatus == 5) {
    if (wrongPasscode) {
      Serial.println("Passcode authentication - Failed");
      error();
      authStatus = 1;
      wrongPasscode = false;
    } else {
      Serial.println("Passcode authentication - Succeeded");
      Serial.println("RSA Authentication - Waiting for agent ID");
      delOutput(4, true);
      authStatus++;
    }
  } else if (authStatus == 6) {
    // TODO
    delay(1);
  }
}