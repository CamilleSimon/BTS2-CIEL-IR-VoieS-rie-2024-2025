// C++ code
//
int key = 6;
void setup()
{
    // ouverture de la liaison à une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
  	//Serial.print("Ceci est un message sur une ligne. ");
    //Serial.println("Ceci est un message sur la meme ligne.");
   	//Serial.println("Ceci est un message sur une deuxieme ligne.");
	
  	
}

void loop()
{
  	char readChar = 0; 
  
  	int buff = Serial.available();
  	
  	while(buff > 0) // tant qu'il reste un caractere
    	{
    		int intChar = Serial.read() + key ;//lecture du caractere
		
      		if(intChar < 123)
        	{
        		readChar = intChar;
        		Serial.print(readChar);
        	}
        	else
        	{
        		int i = intChar - 122;
        		intChar = 96 + i;
          		readChar = intChar;
          		Serial.print(readChar);
      		}
      
    		 buff = Serial.available(); // mise à jour du nombre de caratères restant
     
    	}
}
