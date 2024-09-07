//initialisation de la clé (de valeur 6 ici)
int key = 6;
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
        
        int intChar = readChar + key;
      
        if (intChar > 122) 
         {
           intChar -= 26;
         }
      
      readChar = intChar;
      Serial.print(readChar); // envoi du caractère
      
      buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
}
