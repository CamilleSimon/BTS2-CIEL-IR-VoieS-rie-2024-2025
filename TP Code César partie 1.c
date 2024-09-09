int key = 6;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
  int buff = Serial.available();
  char readChar;

    while(buff > 0)
    {
        readChar = Serial.read();
        
        int intChar = readChar + key;// Correction de la casse ici
     
      // Si le décalage dépasse 'z', le faire revenir au début de l'alphabet
      if(intChar > 122)// Correction ici (casse)
      {
        intChar -= 26;
      }
      
      readChar = intChar;// Afficher le caractère chiffré
      Serial.print(readChar);
      buff = Serial.available();// Mettre à jour le buffer pour éviter une boucle infinie
    }
}