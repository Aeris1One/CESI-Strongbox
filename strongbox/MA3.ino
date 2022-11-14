/*
  MA3
  ---
  Input : Nothing
  Output: If authentication step succeeded, boolean
  Effect: Run authentication step and return if it succeeded
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