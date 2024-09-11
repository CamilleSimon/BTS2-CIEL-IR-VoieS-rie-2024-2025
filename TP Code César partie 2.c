je n'est pas toutes assemblée je vous met les differentes parties 

  DECHIFFREMENT 

void setup()
{
    Serial.begin(9600);
   
  	
}

void loop()
{
	char readChar = 0 ; // caractère à lire
  	char key = 12; // valeurs de la key
  
  
    int buff = Serial.available();

    while(buff > 0 ) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        char cChiff = readChar - key ; 
      
      if( cChiff < 97)
      {
        char cChiff1 = cChiff + 26;
        Serial.print(cChiff1); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
        break ; 
      }
      else 
      {
        Serial.print(cChiff); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      }
    }
}

CHIFFREMENT 
void setup()
{
    Serial.begin(9600);
   
  	
}

void loop()
{
	char readChar = 0 ; // caractère à lire
  	char key = 6; // valeurs de la key
  
  
    int buff = Serial.available();

    while(buff > 0 ) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        char cChiff = readChar + key ; 
      
      if( cChiff > 122)
      {
        char cReste = cChiff - 122;
        char cChiff1 = 97 + cReste;
        Serial.print(cChiff1); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
        break ; 
      }
      else 
      {
        Serial.print(cChiff); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      }
    }
}

OPPERATION 


void setup()
{
    Serial.begin(9600);
}

void loop()
{
  char readChar = 0 ; // caractère à lire
  int tab[10];
  
  
  int buff = Serial.available();
  
  while(buff > 0 ) // tant qu'il reste des caractères dans le buffer
    {
  
}
