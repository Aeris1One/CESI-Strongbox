/*
  Constantes
  Définir les pins connectés aux boutons
*/
const uint8_t button1Pin = 8;
const uint8_t button2Pin = 9;
const uint8_t button3Pin = 10;
const uint8_t button4Pin = 11;

/*
  Déclaration des variables
*/
bool button1Status;
bool button1StatusOld;
bool button2Status;
bool button2StatusOld;
bool button3Status;
bool button3StatusOld;
bool button4Status;
bool button4StatusOld;

/*
  SETUP
  Marquer les pins des boutons comme des entrées
*/
void inputSetup()
{
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
}

/*
  buttonPressed
  ---
  Entrée : Rien
  Sortie : Rien
  Effet  : Retourne le numéro du bouton appuyé
*/
uint8_t buttonPressed()
{
  uint8_t a;

  button1StatusOld = button1Status;
  button1Status = digitalRead(button1Pin);
  button2StatusOld = button2Status;
  button2Status = digitalRead(button2Pin);
  button3StatusOld = button3Status;
  button3Status = digitalRead(button3Pin);
  button4StatusOld = button4Status;
  button4Status = digitalRead(button4Pin);

  /*
    Si le bouton est appuyé et qu'il n'était pas appuyé avant
    alors retourner le numéro du bouton
  */
  if (button1StatusOld == HIGH && button1Status == LOW)
  {
    a = 1;
  } else {
    a = 0;
  }
  
  if (button2StatusOld == HIGH && button2Status == LOW)
  {
    a = a + 2;
  }
  
  if (button3StatusOld == HIGH && button3Status == LOW)
  {
    a = a + 4;
  }
  
  if (button4StatusOld == HIGH && button4Status == LOW)
  {
    a = a + 8;
  }
  return a;
}


/*
  letterToNumber
  ---
  Entrée : char
  Sortie : uint8_t
  Effet  : Retourne le numéro correspondant à la lettre
*/
int letterToNumber(char letter)
{
    return letter - 'A' + 1;
}


/*
  serialFlush
  ---
  Entrée : Rien
  Sortie : Rien
  Effet  : Vide le buffer de la liaison série
*/
void serialFlush(){
  while (Serial.available() != 0)
  {
    int r = Serial.read();
  }
}