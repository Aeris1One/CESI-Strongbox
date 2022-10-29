//     _____ _                         _                 ____   ___   ___   ___  
//    / ____| |                       | |               |___ \ / _ \ / _ \ / _ \ 
//   | (___ | |_ _ __ ___  _ __   __ _| |__   _____  __   __) | | | | | | | | | |
//    \___ \| __| '__/ _ \| '_ \ / _` | '_ \ / _ \ \/ /  |__ <| | | | | | | | | |
//    ____) | |_| | | (_) | | | | (_| | |_) | (_) >  <   ___) | |_| | |_| | |_| |
//   |_____/ \__|_|  \___/|_| |_|\__, |_.__/ \___/_/\_\ |____/ \___/ \___/ \___/ 
//                                __/ |                                          
//                               |___/                                           

// Version 0.1 - Basique

// Constantes
// Pins LEDs
const int led1Pin = 6;
const int led2Pin = 5;
const int led3Pin = 4;
const int led4Pin = 3; 
const int led5Pin = 2;
// Pins Boutons
const int button1Pin = 13;
const int button2Pin = 12;
const int button3Pin = 11;
const int button4Pin = 10;
// Code
const int code1 = 1;
const int code2 = 2;
const int code3 = 3;
const int code4 = 4;

// Variables
int codeStatus;

bool button1Status;
bool button1StatusOld;
bool button2Status;
bool button2StatusOld;
bool button3Status;
bool button3StatusOld;
bool button4Status;
bool button4StatusOld;



// Fonction pour l'erreur de code
void error() {
  // On boucle 3 fois
  int count = 3;
  while (count != 0){
    // Allumer toutes les LEDs
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, HIGH);
    // Patienter 200ms
    delay(200);
    // Eteindre toutes les LEDs
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
    // Patienter encore 200ms
    delay(200);
    // Décrémenter le compteur
    count = count - 1;
  }
}

// Fonction future pour l'ouverture du coffre
void openSafe() {
}

void setup() {
  // Les LEDs sont des sorties
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);

  // Les boutons sont des entrées
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);

  // Quand l'Arduino se lance, on demande la première partie du code
  codeStatus = 1;
}

void loop() {
  /*
  Ici, on définit 2 variables par bouton :
  - buttonXStatus qui est le statut actuel du bouton (Appuyé ou non)
  - buttonXStatusOld qui est le statut du bouton lors de la dernière boucle
  En comparant les 2, on peut trouver le moment exact où le bouton à été appuyé
  */
  button1StatusOld = button1Status;
  button1Status = digitalRead(button1Pin);
  button2StatusOld = button2Status;
  button2Status = digitalRead(button2Pin);
  button3StatusOld = button3Status;
  button3Status = digitalRead(button3Pin);
  button4StatusOld = button4Status;
  button4Status = digitalRead(button4Pin);
  
  /*
  Ici, on crée une variable buttonPressed qui prends le numéro du bouton appuyé.
  On pourra ensuite la comparer au code défini en constante
  */
  int buttonPressed = 0;
  if(button1StatusOld == HIGH && button1Status == LOW){
    buttonPressed = 1;
  }
  if(button2StatusOld == HIGH && button2Status == LOW){
    buttonPressed = 2;
  }
  if(button3StatusOld == HIGH && button3Status == LOW){
    buttonPressed = 3;
  }
  if(button4StatusOld == HIGH && button4Status == LOW){
    buttonPressed = 4;
  }

  // Ce booléen sert à reporter l'incrémentation après les IFs
  // ainsi on évite de rentrer dans plusieurs conditions successivement.
  bool shouldIncrementCodeStatus = false;

  // Si on attends la première valeur du code
  if(codeStatus == 1){
	// Et si le bon bouton est pressé
    if (buttonPressed == code1){
	  // On passe à la seconde valeur du code
      shouldIncrementCodeStatus = true;
	// Sinon, si un bouton est pressé mais que ce n'est pas le bon
    } else if (buttonPressed != 0) {
	  // On lance la séquence d'erreur
      error();
    }
  }
  // On répète pour la seconde valeur du code
  if(codeStatus == 2){
	// Mais cette fois on allume la LED 1 pour confirmer la première valeur
    digitalWrite(led1Pin, HIGH);
    if (buttonPressed == code2){
      shouldIncrementCodeStatus = true;
    } else if (buttonPressed != 0) {
      error();
    }
  }
  // Pour la troisième
  if(codeStatus == 3){
	// Avec cette fois les deux premières LEDs
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    if (buttonPressed == code3){
      shouldIncrementCodeStatus = true;
    } else if (buttonPressed != 0) {
      error();
    }
  }
  // Et enfin la quatrième valeur
  if(codeStatus == 4){
	// Avec les trois premières LEDs allumées
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    if (buttonPressed == code4){
	  // Mais cette fois, si le bouton est le bon, on allume
      // la quatrième LED, on ouvre le coffre, puis on allume
      // la LED verte !
      digitalWrite(led4Pin, HIGH);
      openSafe();
      digitalWrite(led5Pin, HIGH);
    } else if (buttonPressed != 0) {
      error();
    }
  }
  // Et ici, on incrémente si besoin
  // Aprés les boucles pour éviter tout problème !
  if(shouldIncrementCodeStatus){
    codeStatus++;
  }
}