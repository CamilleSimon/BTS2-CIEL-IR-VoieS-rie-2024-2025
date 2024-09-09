
int key=6;

void setup()
{
    Serial.begin(9600);
 	
}

void loop()
{
    char readChar = 0; // caractère à lire
    int buff = 0;
  	int readInt;

    buff = Serial.available();
  
    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
      	readInt = readChar+key;
        // Si le caractère dépasse 'z', recommencer a 'a'
        if (readInt > 'z') {
            readInt = readInt - 26; // Retourner a 'a' après 'z'
        }
     	readChar = readInt;
      
        Serial.print(readChar); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
  
  
  
  
}