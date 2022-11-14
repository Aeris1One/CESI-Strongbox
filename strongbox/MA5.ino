int a = 0;
const uint32_t cardid[16] = {866416, 846317, 983214, 315100, 555611, 661988, 947888, 962210, 120806, 600097, 645984, 978979, 654547, 123158, 985167, 989548};

bool MA5()
{
    Serial.println("Authentification MA5: Entrez votre code agent");
    serialFlush();
    while (Serial.available() == 0)
    {
        // Do nothing, just hang until there's some data to read
        delay(1);
    }
    char a = Serial.readStringUntil('\n').charAt(0);
    Serial.println("Authentification MA5: Veuillez saisir votre CARD_ID");
    serialFlush();
    while (Serial.available() == 0)
    {
        // Do nothing, just hang until there's some data to read
        delay(1);
    }
    uint32_t b = Serial.parseInt();
    if (b == cardid[letterToNumber(a) - 1])
    {
        Serial.println("Authentification MA5: Code vérifié.");
        return true;
    }
    else
    {
        Serial.println("Authentification MA5: Code incorrect.");
        return false;
    }
}