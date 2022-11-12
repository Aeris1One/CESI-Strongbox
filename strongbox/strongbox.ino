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

}