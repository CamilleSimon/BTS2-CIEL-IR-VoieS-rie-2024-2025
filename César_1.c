int cle = 6;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    char password = 0;
    int charInt;
    int buff = 0;

    buff = Serial.available();

    while (buff > 0)
    {

        password = Serial.read();
        charInt = password + cle;


        if (charInt > 'z') {
            charInt = charInt - 26;
        }

        password = charInt;
        Serial.print(password);
        buff = Serial.available();
    }
}