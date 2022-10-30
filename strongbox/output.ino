/*
  Constants
  Define pins connected to DELs
*/
const int del1Pin = 6;
const int del2Pin = 5;
const int del3Pin = 4;
const int del4Pin = 3; 
const int delGreenPin = 2;

/*
  setup
  ---
  Mark all pins connected to DELs as output
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
  Input : Nothing
  Output: Nothing
  Effect: Turn on then off all red leds with a delay of 300 ms, three times
*/
void error() {
  // On boucle 3 fois
  int count = 3;
  while (count != 0){
    // Allumer toutes les LEDs
    delOutput(4,false);
    // Patienter 200ms
    delay(200);
    // Eteindre toutes les LEDs
    delOutput(0,false);
    // Patienter encore 200ms
    delay(200);
    // Décrémenter le compteur
    count = count - 1;
  }
}

/*
  delOutput
  ---
  Input : Integrer "red", boolean "green"
  Output: Nothing
  Effect: Turn on the number of red DEL specified as input. Turn off the excedant.
          Turn on or off the green DEL according to input.
*/
void delOutput(int red, bool green){
  if(red>=1){
    digitalWrite(del1Pin, HIGH);
  } else {
    digitalWrite(del1Pin, LOW);
  }
  if(red>=2){
    digitalWrite(del2Pin, HIGH);
  } else {
    digitalWrite(del2Pin, LOW);
  }
  if(red>=3){
    digitalWrite(del3Pin, HIGH);
  } else {
    digitalWrite(del3Pin, LOW);
  }
  if(red>=4){
    digitalWrite(del4Pin, HIGH);
  } else {
    digitalWrite(del4Pin, LOW);
  }
  if(green){
    digitalWrite(delGreenPin, HIGH);
  } else {
    digitalWrite(delGreenPin, LOW);
  }
}