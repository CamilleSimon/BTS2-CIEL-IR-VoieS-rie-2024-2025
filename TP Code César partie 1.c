// Définir la clé globale pour le chiffrement
int key = 6;

void setup() {
  // Initialiser la communication série
  Serial.begin(9600);
}

void loop() {
  int buff =Serial.available();
  char readChar;

  while(buff > 0)
  {
      readChar =Serial.read();
      int intChar = readChar + key;
      
      // Si le décalage dépasse 'z', le faire revenir au début de l'alphabet
      if (intchar > 122) {
        intchar -= 26;
      }
      
      // Afficher le caractère chiffré
       readChar = intchar;
      Serial.print(readChar);
  }

    
    
  
}


