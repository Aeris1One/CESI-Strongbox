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
  int buttonVar = buttonPressed();
  if (MA1Status == 0) {
    // Envoie la première question
    Serial.println("Question numero 1 : combien y a t-il d'agent au sein de l'agence 1) 9 ; 2) 14 ; 3) 16 ; 4) 404 ");
    MA1Status++;
  } else if (MA1Status == 1) {
    if (buttonVar == 3){
      // Envoyer "bonne réponse"
      // Incrémenter MA1Status
      Serial.println("Bonne réponse, bravo. Passons a la prochaien question");
      MA1Status++;
    } else if (buttonVar != -1) {
      // Mauvaise réponse !
      // Retour à MA1Status = 0
      // Déclencher la séquence d'erreur
      Serial.println("Mauvaise réponse. Vous n'êtes pas l'un de nos agents");
      MA1Status = 0;
      error();
    }
  } else if (MA1Status == 2) {
    Serial.println("Question numéro 2 : quel est le vrai nom des cette patisserie 1) pain au chocolat ; 2) chocolatine ; 3) pain au chocolatine ; 4) croissant au chocolat");
    MA1Status++;
  } else if (MA1Status == 3) {
    if (buttonVar == 1){
      // Envoyer "bonne réponse"
      // Incrémenter MA1Status
      Serial.println("Bonne réponse, bravo. Passons a la prochaine question");
      MA1Status++;
    } else if (buttonVar != -1) {
      // Mauvaise réponse !
      // Retour à MA1Status = 0
      // Déclencher la séquence d'erreur
      Serial.println("Mauvaise réponse. Vous n'êtes pas l'un de nos agents");
      MA1Status = 0;
      error();
    }
  } else if (MA1Status == 4) {
    Serial.println(" Question numéro 3 : est tu quelqu'un avec de méchant 1) non ; 2) oui");
    MA1Status++;
  } else if (MA1Status == 5) {
    if (buttonVar == 1){
      // Envoyer "bonne réponse"
      // Incrémenter MA1Status
      Serial.println("Bonne réponse, bravo. Passons a la prochaine question");
      MA1Status++;
    } else if (buttonVar != -1) {
      // Mauvaise réponse !
      // Retour à MA1Status = 0
      // Déclencher la séquence d'erreur
      Serial.println("Mauvaise réponse. Vous n'êtes pas l'un de nos agents");
      MA1Status = 0;
      error();
    }
  } else if (MA1Status == 6) {
    Serial.println("Question numéro 4: quel est le nom de l'associé qui est tombé dans le coma après avoir effectués un trible dab retournés 1) Roger ; 2) Didier ; 3) Jean-Eude ; 4) Vincent");
    MA1Status++;
  } else if (MA1Status == 7) {
    if (buttonVar == 4){
      // Envoyer "bonne réponse"
      // Incrémenter MA1Status
      Serial.println("Bonne réponse, bravo. Vous passez cette épreuve de sécurité");
      MA1Status++;
    } else if (buttonVar != -1) {
      // Mauvaise réponse !
      // Retour à MA1Status = 0
      // Déclencher la séquence d'erreur
      Serial.println("Mauvaise réponse. Vous n'êtes pas l'un de nos agents");
      MA1Status = 0;
      error();
    }
  }
  if (MA1Status==8){
    return true;
  } else {
    return false;
  }
}
 