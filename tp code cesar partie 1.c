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
        int intChar = readChar + 6; // caractère à lire
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      if (intChar > 122)
      {
       intChar = intChar -26; 
      }
      readChar = intChar;
      Serial.print(readChar); // envoi du caractère
    }
}
