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

void setup() {
  // When starting, we're asking for the passcode's first character
  codeStatus = 1;
}

void loop() {
  // If we're waiting for the passcode's first character
  if(codeStatus == 1){
	  // And if the correct button is pressed
    if (buttonPressed() == code1){
	    // Then we ask for the second character
      codeStatus++
      // And turn on the correct number of DELs
      delOutput(1, false)
	  // Else, if a button is pressed but not the correct one
    } else if (buttonPressed() != 0) {
	    // We output an error
      error();
    }
  }

  // Let's repeat for the second character
  else if(codeStatus == 2){
    if (buttonPressed() == code2){
      codeStatus++
      delOutput(2, false)
    } else if (buttonPressed() != 0) {
      error();
    }
  }

  // Then for the third
  else if(codeStatus == 3){
    if (buttonPressed() == code3){
      codeStatus++
      delOutput(3, false)
    } else if (buttonPressed() != 0) {
      error();
    }
  }

  // And finally the last one
  else if(codeStatus == 4){
    if (buttonPressed() == code4){
      // But this time if the character is correct we open the safe and turn on the green DEL
      delOutput(4, true)
      openSafe();
    } else if (buttonPressed != 0) {
      error();
    }
  }
}