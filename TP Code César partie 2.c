// C++ code
//
int operation;
int key;
void setup()
{
    // ouverture de la liaison à une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
  	int buff = Serial.available();
  
  	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {	
    	String string1;
    	string1 = string1 + Serial.read();
      	buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
  	
  	//char sep = ',';
  	//tokens = split(str, sep)
  	operation = string1[0];
    key = string1[1];
  	char mot = string1[2];
  	if (operation = 0)
	{
		chiffrement(char mot);
	}
	else
	{
		dechiffrement(char mot);
	}
  
}

void loop()
{
  
}

void chiffrement(char mot);
{

  
}
  
void dechiffrement(char mot);
{
  
  
}
  
  
}
      	
