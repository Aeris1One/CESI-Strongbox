/*
  Constantes
  Définir les pins connectés aux DELs
*/
const uint8_t del1Pin = 4;
const uint8_t del2Pin = 5;
const uint8_t del3Pin = 6;
const uint8_t del4Pin = 7;
const uint8_t delGreenPin = 3;


/*
  Variables
  failedAuth : nombre d'erreur d'authentifications
  lockTime : durée (en dizièmes de secondes) pendant laquelle le coffre se vérouille la première fois (après 3 erreurs, double à chaque erreur supplémentaire)
*/
uint8_t failedAuth = 0;
uint16_t lockTime = 300;

/*
  setup
  ---
  Définir tous les pins des DELs comme des sorties
*/
void outputSetup() {
  pinMode(del1Pin, OUTPUT);
  pinMode(del2Pin, OUTPUT);
  pinMode(del3Pin, OUTPUT);
  pinMode(del4Pin, OUTPUT);
  pinMode(delGreenPin, OUTPUT);
}

/*
  error
  ---
  Entrée : Rien
  Sortie : Rien
  Effet  : Affiche un animation d'erreur et bloque si nécessaire le programme
*/
void error() {
  // Envoyer un signal d'erreur sur la communication série
  Serial.println("Authentication en erreur");
  
  // Bloquer le coffre si nécessaire
  if (failedAuth == 3) {
    // Envoyer le temps de verrouillage via la communication série
    Serial.print("Trop d'essai raté, blockage du coffre pendant");
    Serial.print(lockTime / 10);
    Serial.println(" secondes");

    // Verrouiller le coffre pendant le temps défini
    lock(lockTime);

    // Doubler le temps défini pour le prochain verrouillage
    lockTime = lockTime * 2;
    
    // N.B: Pas besoin de décrémenter failedAuth, car il n'est pas incrémenté
    //     dans la fonction si le coffre se verrouille
  } else {
    // Incrémentation du nombre d'erreur d'authentification
    failedAuth++;
  }

  // Boucler 3 fois
  uint8_t count = 3;
  while (count != 0) {
    delOutput(4, false);
    // Allumer toutes les DELs
    // Attendre 200ms
    delay(200);
    // Eteinre toutes les DELs
    delOutput(0, false);
    // Attendre encore 200ms
    delay(200);
    // Décrémenter le compteur
    count--;
  }
}

/*
  lock
  ---
  Entrée : time : durée (en dizièmes de secondes) pendant laquelle le coffre se vérouille
  Sortie : Rien
  Effet  : Verrouille le coffre pendant le temps défini
*/
void lock(uint8_t time) {
  uint8_t delsOn = 0;
  while (time != 0) {
    if (delsOn <= 4) {
      delsOn++;
    } else {
      delsOn = 0;
    }
    delOutput(delsOn, false);
    time--;
    delay(100);
  }
}

/*
  delOutput
  ---
  Entrée : red : nombre de DELs rouges à allumer
           green : booléen, si la DEL verte doit être allumée
  Sortie : Rien
  Effet  : Allume les DELs rouges et la DEL verte si nécessaire
*/
void delOutput(uint8_t red, uint8_t green) {
  if (red >= 1) {
    digitalWrite(del1Pin, HIGH);
  } else {
    digitalWrite(del1Pin, LOW);
  }
  if (red >= 2) {
    digitalWrite(del2Pin, HIGH);
  } else {
    digitalWrite(del2Pin, LOW);
  }
  if (red >= 3) {
    digitalWrite(del3Pin, HIGH);
  } else {
    digitalWrite(del3Pin, LOW);
  }
  if (red >= 4) {
    digitalWrite(del4Pin, HIGH);
  } else {
    digitalWrite(del4Pin, LOW);
  }
  if (green) {
    digitalWrite(delGreenPin, HIGH);
  } else {
    digitalWrite(delGreenPin, LOW);
  }
}