/*
  MA
  ---
  Entrée : Rien
  Sortie : Booléen, si la méthode a réussi
  Effet  : Tente l'authentification MA4, répondre true si succès, false sinon
*/
bool MA4()
{
    Serial.println("Authentification MA4: Initialisation du Scan digital");
    delay(2000);
    Serial.println("Authentification MA4: Veuiller présentez votre main");
    Serial.println("Authentification MA4: Analyse de l'empreinte, veuillez ne pas bouger votre main");
    delay(2000);
    Serial.println("Authentification MA4: Empreinte reconnue");
    return true;
}