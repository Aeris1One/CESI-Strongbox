/*
  Constant
  Define a table which link a key to an agent
*/
const uint16_t pubkey[16] = {601, 619, 631, 641, 647, 653, 661, 673, 691, 701, 733, 739, 751, 797, 809, 811};

bool MA2()
{
  Serial.println("Authentification MA2: Entrez votre nom d'agent");
  serialFlush();
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  char d = Serial.readStringUntil('\n').charAt(0);
  uint16_t e = pubkey[letterToNumber(d) - 1];
  uint16_t m = 0;
  uint16_t c = 0;
  m = random(1,2880);
  c = encrypt(m, e);
  if (c == 0)
  {
    Serial.println("Authentification MA2: Erreur de chiffrement");
    return false;
  }
  Serial.print("Authentification MA2: Veuillez déchiffrer ce code : ");
  Serial.println(c);

  // !!!!!!DEBUG!!!!!!
  Serial.print("***Débug prototype: Vous devriez trouver ");
  Serial.println(m);
  // !!!!À RETIRER!!!!

  Serial.println("Authentification MA2: Saissisez votre code déchiffré.");
  serialFlush();
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  uint32_t M = Serial.parseInt();
  if (M==m){
    Serial.println("Authentification MA2: Code valide");
    return true;
  }
  else{
    Serial.println("Authentification MA2: Code invalide");
    return false;
  }
}