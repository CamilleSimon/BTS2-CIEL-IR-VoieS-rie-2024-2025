int key = 6;

void setup() {
    Serial.begin(9600);
}

void loop() {
    char readChar = 0; // caractère à lire
    int charInt;
    int buff = 0;

    buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        charInt = readChar + key; // Ajout de la cle au caractère
        if (charInt > 122) {
            charInt = (charInt - 123) + 97;
        }
        readChar = charInt;
        Serial.print(readChar); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
}