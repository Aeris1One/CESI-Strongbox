// Constants
const uint16_t cardModelVoltage[8][2] = {{322, 326}, {507, 512}, {605, 610}, {837, 843}, {852, 856}, {864, 871}, {700, 704}, {888, 894}};

/*
  isCardInserted
  ---
  Input : Nothing
  Output: If a card is inserted, boolean
  Effect: Return if a card is inserted
*/
uint8_t isCardInserted()
{
  return (analogRead(A0) != 0);
}

/*
  cardModel
  ---
  Input : Nothing
  Output: The card model
  Effect: Return the card model
*/
uint8_t cardModel()
{
    int cardVoltage = analogRead(A0);
    for (int i = 0; i < 7; i++)
    {
        if (cardVoltage >= cardModelVoltage[i][0] && cardVoltage <= cardModelVoltage[i][1])
        {
            return i + 1;
        }
    }
}