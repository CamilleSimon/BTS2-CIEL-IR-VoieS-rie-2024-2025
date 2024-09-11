int operation = Serial.read();

void setup()
{
    Serial.begin(9600);
}

String chiffrement()
{
    if (operation == 0)
    {
        int key = serial.read()
        char readChar = 0; // caractère à lire
        int buff = Serial.available();
            while(buff > 0)
            {
                readChar = Serial.read();
                int intChar = readChar + key;
                    if (intChar > 122)
                    {
                        intChar = intChar - 26;
                    }
                    int messagechiffre = intChar;
                    return messagechiffre;
            }
    }
}

String dechiffrement()
{
    if (operation == 1)
    {
        int key = serial.read()
        char readChar = 0; // caractère à lire
        int buff = Serial.available();
            while(buff > 0)
            {
                readChar = Serial.read();
                int intChar = readChar - key;
                    if (intChar > 122)
                    {
                        intChar = intChar - 26;
                    }
                    int messagedechiffre = intChar;
                    return messagedechiffre;
            }
    }
}

void loop()
{
    int tab[10];
    int i = 0
    while (i < 10)
    {
        tab[i] = 

        i++;
    }
}
