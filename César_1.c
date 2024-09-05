void setup()
{
    Serial.begin(9600);
}

void loop()
{
    char password = 0;
    int buff = 0;
    int cle = 6;

    buff = Serial.available();

    while (buff > 0)
    {
        password = Serial.read();
        password = password + cle;

        if (password > 'z') {
            password = password - 26;
        }

        if (password >= 'a' && password <= 'z') {
            Serial.print(password);
        }

        buff = Serial.available();
    }
}