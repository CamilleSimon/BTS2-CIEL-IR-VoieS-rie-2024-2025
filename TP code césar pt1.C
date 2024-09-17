void setup()
{
    Serial.begin(9600);
}

void loop()
{  
	char readChar = 0; // caractère à lire
	int key = 6;
	int buff = Serial.available(); // mise à jour du nombre de caratères restant

    if(buff > 0)
    {
        	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    		{
       		readChar = Serial.read(); // lecture du caractère

		if(readChar == 122)
		{
		readChar = 96 = key;
		}
		else
		{
      		readChar = readChar + key; // Pour chiffrer un message
      		if(readChar > 122)
       	 	{
         	readChar = readChar - 26 ; 
        	}
		}
      
      
        	Serial.print(readChar); // envoi du caractère
        	buff = Serial.available(); // mise à jour du nombre de caratères restant 		
            }
     }
}      
