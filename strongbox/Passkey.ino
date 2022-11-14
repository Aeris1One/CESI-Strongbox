uint8_t passKey[4] = {5, 2, 3, 4};

bool passkey() {
  // !!!!!!!!!!!DEBUG!!!!!!!!!!!
  return true;
  // !!!!!!!!À RETIRER!!!!!!!!!!
  
  bool rightPasskey = true;
  for (int i = 0; i < 4; i++) {
    int buttonVar = buttonPressed();
    while (buttonVar == 0)
    {
      delay(1000);
      buttonVar = buttonPressed();
    }
    if (buttonVar == passKey[i]) { 
      Serial.print("Vous avez entré : ");
      Serial.println(buttonVar);
      Serial.print("Correct (");
      Serial.print(i+1);
      Serial.println("/4)");
      delay(1000);
    }
    else
    {
      Serial.print("Vous avez entré : ");
      Serial.println(buttonVar);
      Serial.print("Incorrect (");
      Serial.print(i+1);
      Serial.println("/4)");
      delay(1000);
      rightPasskey = false;
    }
    delOutput(i, false);
  }
  return rightPasskey;
}