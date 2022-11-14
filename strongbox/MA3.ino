/*
  MA3
  ---
  Entrée : Rien
  Sortie : Booléen, si la méthode a réussi
  Effet  : Tente l'authentification MA3, répondre true si succès, false sinon
*/
bool MA3()
{
    Serial.println("Authentification MA3: Initialisation du Scan rétinien");
    delay(2000);
    Serial.println("Authentification MA3: Veuiller présentez votre rétine");
    Serial.println("Authentification MA3: Analyse de la rétine, veuillez ne pas bouger");
    delay(2000);
    Serial.println("Authentification MA3: Rétine reconnue");
    return true;
}