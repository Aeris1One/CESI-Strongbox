// Constants
// Card pin
const uint8_t cardPin = 0;

uint8_t cardModelVoltage[8][2] = {{100, 200}, {200, 300}, {300, 400}, {400, 500}, {500, 600}, {600, 700}, {700, 800}, {800, 900}};

uint8_t isCardInserted()
{
    return (digitalRead(CARD_DETECT_PIN) != 0);
}

uint8_t cardModel()
{
    int cardVoltage = analogRead(cardPin);
    for (i = 0, i = 7, i++)
    {
        if (cardVoltage >= cardModelVoltage[i][0] && cardVoltage <= cardModelVoltage[i][1])
        {
            return i;
        }
    }
}