uint8_t passKey[4] = {5, 2, 3, 4};

void passkey() {
  for (int i = 0; i < 4; i++) {
    while (buttonPressed() == 0)
    {
      delay(1);
    }
    if (buttonPressed()) == passKey[i] { 
      Serial.println("Correct");
    }
    else {
      Serial.println("Incorrect");
    }
  }
}