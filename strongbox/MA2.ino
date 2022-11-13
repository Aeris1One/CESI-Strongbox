/*
  Constant
  Define a table which link a key to an agent
*/
const uint16_t pubkey[16] = {601, 619, 631, 641, 647, 653, 661, 673, 691, 701, 733, 739, 751, 797, 809, 811};

bool MA2()
{
  Serial.println("Entrez votre nom d'agent");
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  String d = Serial.readStringUntil('\n');
  int e = pubkey[letterToNumber(d) - 1];
  int m = 0;
  int c = 0;
  m = random(1,2880);
  c = modexp(m, e, n);
  Serial.print("Veuillez déchiffrer ce code : ");
  Serial.println(c);
  Serial.println("Saissisez votre code déchiffré.");
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  int M = Serial.readStringUntil('\n');
  if (M==m){
    return true
  }
  else{
    return false
  }
}