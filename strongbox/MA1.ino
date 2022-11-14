int MA1Status = 0;

/*
MA1Status = 0 : print the first question
MA1Status = 1 : wait for the first answer
MA1Status = 2 : print the second question
MA1Status = 3 : wait for the second answer
MA1Status = 4 : print the third question
MA1Status = 5 : wait for the third answer
*/
bool MA1() {
  // QUESTION 1
  Serial.println("Question numero 1 : combien y a t-il d'agent au sein de l'agence :\n1) 9\n2) 14\n3) 16\n4) 418");
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  int answer = Serial.parseInt();
  if (answer == 4){
    Serial.println("I'm a teapot");
  }
  if (answer != 3){
    return false;
  }

  serialFlush();

  // QUESTION 2
  Serial.println("Question numéro 2 : quel est le vrai nom des cette patisserie ?\n1) pain au chocolat\n2) chocolatine\n3) petit pain\n4) croissant au chocolat");
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  answer = Serial.parseInt();
  if (answer != 1){
    return false;
  }

  serialFlush();

  // QUESTION 3
  Serial.println(" Question numéro 3 : est tu quelqu'un avec de méchant ?\n1) non\n2) oui");
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  answer = Serial.parseInt();
  if (answer != 1){
    return false;
  }

  serialFlush();

  // QUESTION 4
  Serial.println("Question numéro 4: quel est le nom de l'associé tombé dans le coma après avoir effectué un multi-dab retourné ?\n1) Roger\n2) Didier\n3) Jean-Eude\n4) Vincent");
  while (Serial.available() == 0)
  {
    // Do nothing, just hang until there's some data to read
    delay(1);
  }
  answer = Serial.parseInt();
  if (answer != 4){
    return false;
  }
  

  // If all question passed, exit with true
  return true;
}
 