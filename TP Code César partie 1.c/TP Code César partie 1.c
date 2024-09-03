```
//Voici mon 1er code pour le TP César
// C++ code
//

void setup()
{
Serial.begin(9600);
}

void loop()
{
    char readChar = 0; // caractère à lire
    int buff = 0;

    buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
      int key = 6;
        Serial.print(readChar + 6); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
}
```