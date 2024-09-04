
int key=6;

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
      	readChar = readChar+key;
        // Si le caractère dépasse 'z', recommencer a 'a'
        if (readChar > 'z') {
            readChar = readChar - 26; // Retourner a 'a' après 'z'
        }
        Serial.print(readChar); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
  
  
  
  
}