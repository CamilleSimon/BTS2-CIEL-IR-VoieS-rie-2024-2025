// C++ code
//
char operation = -1;
int key;
String key2;
char res;

void print(const char* format, ...);

void setup()
{
    // ouverture de la liaison à une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
}

void loop()
{
  	char readChar;
  	int buff = Serial.available();
  	String string1;
  
  
  	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {	
      	delay(10);
    	readChar = Serial.read();
    	string1 = string1 +readChar;
      	//print("%s", string1);
      	buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
  
  
  	if (string1 != NULL) {
        int virg1 = 1;
        int virg2 = string1.indexOf(',',2);

        int diff_virg = virg2 - virg1 + 1;

        operation = string1[0];
      	Serial.print(operation);
      
      	
        key2 = string1.substring(2,diff_virg);

      	Serial.print(key2);
        int longueur = string1.length()- virg2 +1;
      
        String mot;
      
        for(int l = 1; l < longueur; l++)
        {
          	delay(10);
            mot = mot + string1[virg2+l]; 
        } 

        if (operation == 0)
        {
            chiffrement(mot);
        }
    	else
      	{
          	dechiffrement(mot);
    	}
	
    }
  	
}

String chiffrement(String mot)
{
  	int longueur2 = mot.length();
	for(int j = 0; j < 1; j++)
    {
      	//Serial.print(mot[j]);
    	res = mot[j] + key;
      	//Serial.print(res);
	}
  	
}

String dechiffrement(String mot)
{
  	int longueur3 = mot.length();
	for(int k = 0; k < longueur3; k++)
    {
    	res = mot[k] - key;
        //Serial.print(res);
	}
  	
}
  


void print(const char* format, ...)
{
  char buffer[512];

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);

  Serial.println(buffer);
}   
