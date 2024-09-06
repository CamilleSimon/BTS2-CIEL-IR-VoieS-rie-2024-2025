int key = 6;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read() + key; // lecture du caractère
      	char result = readChar;
      	if (result > 'z')
      	{
          	char result = readChar - 26; // permet de revenir à a
        	Serial.print(result); // envoi du caractère
        
      	}
      	else
      	{
        	Serial.print(result); // envoi du caractère   
      	}
      	buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
} 
