
int a = 0;
const uin32_t cardid[16] = {866416, 846317, 983214, 315100, 555611, 661988, 947888, 962210, 120806, 600097, 645984, 978979, 654547, 123158, 985167, 989548};
char agent[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'};

bool MA5()
{
    Serial.println("Entrez votre nom d'agent");
    while (Serial.available() == 0)
    {
        // Do nothing, just hang until there's some data to read
        delay(1);
    }
    String a = Serial.readStringUntil('\n');
    Serial.println("Veuillez saisir votre CARD_ID");
    while (Serial.available() == 0)
    {
        // Do nothing, just hang until there's some data to read
        delay(1);
    }
    String b = Serial.readStringUntil('\n');
    if (b == cardid[letterToNumber(a) - 1])
    {
        Serial.println("Code vérifié.") return True;
    }
    else
    {
        Serial.println("Code incorrect.") return False;
    }
}