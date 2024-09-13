int key = 6;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char readChar = 0; // caractère à lire

  int buff = Serial.available();

  int charcesar;

  while (buff > 0)
  {
    readChar = Serial.read(); // lecture du caractère

    charcesar = key + readChar;

    // Gestion du dépassement pour les lettres en fin d'alphabet
    if (charcesar > 'z') {
      charcesar = 'a' + (charcesar - 'z' - 1);
      
    }
    
    char result = charcesar;
    Serial.print(charcesar); // envoi du caractère
    buff = Serial.available();
  }
}
