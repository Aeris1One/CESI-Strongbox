// Fonction future pour l'ouverture du coffre
void openSafe()
{
  Serial.println("Safe opened");
  Serial.println("Will re-lock in 5 seconds");
  delay(5000);
  Serial.println("Safe re-locked");
}