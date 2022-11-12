// Variables
uint8_t passStatus;
bool wrongPasscode;

void passkey() {
  // Call buttonPressed and store its output as buttonVar
  // This ensure the button isn't released during the loop execution
  int8_t buttonVar = buttonPressed();

  /*
    auth loop
    passStatus define what is the state of authentication ongoing

    passStatus = 1 : wait for passcode first character input (blocking)
    passStatus = 2 : wait for passcode second character input (blocking)
    passStatus = 3 : wait for passcode third character input (blocking)
    passStatus = 4 : wait for passcode fourst character input (blocking)
    passStatus = 5 : verifying passcode inputs
    passStatus = 6 : wait for agent code input (blocking)
    passStatus = 7 : output encrypted random number
    passStatus = 8 : wait for decrypted number input (blocking)
    passStatus = 9 : verify number correspondance
    passStatus = 10: opening vault

    passStatus 5 and 9 are verifications, if one of them fail, revert back to 1.
  */

  if (passStatus == 1) {
    if (buttonVar > 0) {
      if (buttonVar == code1) {
        Serial.println("Passcode authentication - Correct 1/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 1/4");
      }
      passStatus++;
      delOutput(1, false);
    }
  } else if (passStatus == 2) {
    if (buttonVar > 0) {
      if (buttonVar == code2) {
        Serial.println("Passcode authentication - Correct 2/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 2/4");
      }
      passStatus++;
      delOutput(2, false);
    }
  } else if (passStatus == 3) {
    if (buttonVar > 0) {
      if (buttonVar == code3) {
        Serial.println("Passcode authentication - Correct 3/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 3/4");
      }
      passStatus++;
      delOutput(3, false);
    }
  } else if (passStatus == 4) {
    if (buttonVar > 0) {
      if (buttonVar == code4) {
        Serial.println("Passcode authentication - Correct 4/4");
      } else {
        wrongPasscode = true;
        Serial.println("Passcode authentication - Incorrect 4/4");
      }
      passStatus++;
      delOutput(4, false);
    }
  } else if (passStatus == 5) {
    if (wrongPasscode) {
      Serial.println("Passcode authentication - Failed");
      error();
      passStatus = 1;
      wrongPasscode = false;
    } else {
      Serial.println("Passcode authentication - Succeeded");
      Serial.println("RSA Authentication - Waiting for agent ID");
      delOutput(4, true);
      passStatus++;
    }
  } else if (passStatus == 6) {
    // TODO
    delay(1);
  }
}