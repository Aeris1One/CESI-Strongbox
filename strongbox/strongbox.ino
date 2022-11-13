//     _____ _                         _                 ____   ___   ___   ___
//    / ____| |                       | |               |___ \ / _ \ / _ \ / _ \ 
//   | (___ | |_ _ __ ___  _ __   __ _| |__   _____  __   __) | | | | | | | | | |
//    \___ \| __| '__/ _ \| '_ \ / _` | '_ \ / _ \ \/ /  |__ <| | | | | | | | | |
//    ____) | |_| | | (_) | | | | (_| | |_) | (_) >  <   ___) | |_| | |_| | |_| |
//   |_____/ \__|_|  \___/|_| |_|\__, |_.__/ \___/_/\_\ |____/ \___/ \___/ \___/
//                                __/ |
//                               |___/

// Version 0.1 - Basique

// Use variable type from stdint
// https://learn.adafruit.com/deciphering-strange-arduino-code/stdint
#include <stdint.h>

// Constants
// Security tier for each card model

// niveau de sécurité 1 : MA1 + MA3              : modèles -> 1
// niveau de sécurité 2 : MA1 + MA4              : modèles -> 2 et 8
// niveau de sécurité 3 : MA2 + MA5              : modèles -> 3 et 7
// niveau de sécurité 4 : MA2 + MA3 + MA4        : modèles -> 4 et 6
// niveau de sécurité 5 : MA1 + MA2 + MA3 + MA5  : modèles -> 5

uint8_t cardSecurityTier[8] = {1, 2, 3, 4, 5, 4, 3, 2};
bool securityTierMethods[5][5] = {{true, false, true, false, false},
                                  {true, false, false, true, false},
                                  {false, true, false, false, true},
                                  {false, true, true, true, false},
                                  {true, true, true, false, true}};

void setup()
{
  // Setup input.ino and output.ino
  inputSetup();
  outputSetup();

  // And no LED is on
  delOutput(0, false);

  // Initiate Serial connection
  Serial.begin(9600);
}

// FULL REWRITE NEEDED
void loop()
{
  // If a card is inserted
  if isCardInserted ()
  {
    // And if the passkey auth passed successfully
    if passkey ()
    {
      // If necessary, run MA1
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][0])
      {
        if (!MA1())
        {
          error();
          return;
        }
      }
      // If necessary, run MA2
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][1])
      {
        if (!MA2())
        {
          error();
          return;
        }
      }
      // If necessary, run MA3
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][2])
      {
        if (!MA3())
        {
          error();
          return;
        }
      }
      // If necessary, run MA4
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][3])
      {
        if (!MA4())
        {
          error();
          return;
        }
      }
      // If necessary, run MA5
      if (securityTierMethods[cardSecurityTier[cardModel() - 1]][4])
      {
        if (!MA5())
        {
          error();
          return;
        }
      }
      // If all the methods passed, the authentication succeeded
      openSafe();
      return;
    }
  }
