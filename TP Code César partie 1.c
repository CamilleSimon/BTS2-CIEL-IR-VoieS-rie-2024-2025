// C++ code
//
int key = 6;

void setup()
{
    // ouverture de la liaison à une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
  
}


  

void loop ()
{
   char readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
      readChar = Serial.read();// lecture du caractère 
      if (readChar >= 117) 
      
       {
          readChar = readChar - 26;
        }
      readChar = readChar + key;  
      Serial.print(readChar);// envoi du caractère
      buff = Serial.available();// mise à jour du nombre de caractère restant   
    }
      
}  
