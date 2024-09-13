int key=6; // declaration global key

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    char readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
      	readChar = readChar + key; // message chiffrer
        Serial.print(readChar); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
}
