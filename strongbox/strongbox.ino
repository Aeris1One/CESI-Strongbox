//     _____ _                         _                 ____   ___   ___   ___
//    / ____| |                       | |               |___ \ / _ \ / _ \ / _ \ 
//   | (___ | |_ _ __ ___  _ __   __ _| |__   _____  __   __) | | | | | | | | | |
//    \___ \| __| '__/ _ \| '_ \ / _` | '_ \ / _ \ \/ /  |__ <| | | | | | | | | |
//    ____) | |_| | | (_) | | | | (_| | |_) | (_) >  <   ___) | |_| | |_| | |_| |
//   |_____/ \__|_|  \___/|_| |_|\__, |_.__/ \___/_/\_\ |____/ \___/ \___/ \___/
//                                __/ |
//                               |___/

// Version 1.0 - Prototype final

// Nous utilisons les types de données de stdint.h
// https://learn.adafruit.com/deciphering-strange-arduino-code/stdint
#include <stdint.h>

// Constantes
// Niveaux de sécurité
// Niveau de sécurité 1 : MA1 + MA3              : modèles -> 1
// Niveau de sécurité 2 : MA1 + MA4              : modèles -> 2 et 8
// Niveau de sécurité 3 : MA2 + MA5              : modèles -> 3 et 7
// Niveau de sécurité 4 : MA2 + MA3 + MA4        : modèles -> 4 et 6
// Niveau de sécurité 5 : MA1 + MA2 + MA3 + MA5  : modèles -> 5

uint8_t cardSecurityTier[8] = {1, 2, 3, 4, 5, 4, 3, 2};
bool securityTierMethods[5][5] = {{true, false, true, false, false},
                                  {true, false, false, true, false},
                                  {false, true, false, false, true},
                                  {false, true, true, true, false},
                                  {true, true, true, false, true}};

void setup()
{
  // Initialiser input.ino et output.ino
  inputSetup();
  outputSetup();

  // Désactiver toutes les DELs
  delOutput(0, false);

  // Initialiser la communication série
  Serial.begin(9600);
  Serial.println("Initialisation...");

  // Définir la seed pour la fonction 'random'
  // Le port analogique 5 est déconnecté et recoit donc des données pseudo-aléatoires
  randomSeed(analogRead(5));

  Serial.println(F("Coffre initialisé, en attente de carte..."));
}

void loop()
{
  // Si une carte est détectée
  if (isCardInserted())
  {
    Serial.println(F("Carte insérée, mot de passe requis"));
    // Et que le mot de passe est correct
    if (passkey())
    {
      // Si nécessaire, exécuter MA1
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][0])
      {
        if (!MA1())
        {
          // Si une erreur est survenue dans MA1, afficher une erreur et quitter
          error();
          return;
        }
      }
      // Si nécessaire, exécuter MA2
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][1])
      {
        if (!MA2())
        {
          // Si une erreur est survenue dans MA2, afficher une erreur et quitter
          error();
          return;
        }
      }
      // Si nécessaire, exécuter MA3
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][2])
      {
        if (!MA3())
        {
          // Si une erreur est survenue dans MA3, afficher une erreur et quitter
          error();
          return;
        }
      }
      // Si nécessaire, exécuter MA4
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][3])
      {
        if (!MA4())
        {
          // Si une erreur est survenue dans MA4, afficher une erreur et quitter
          error();
          return;
        }
      }
      // Si nécessaire, exécuter MA5
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][4])
      {
        if (!MA5())
        {
          // Si une erreur est survenue dans MA5, afficher une erreur et quitter
          error();
          return;
        }
      }
      // Si toutes les méthodes d'authentification nécessaires ont été exécutées avec succès, afficher un message de succès
      openSafe();
      return;
    } else {
      error();
      return;
    }
  }
}