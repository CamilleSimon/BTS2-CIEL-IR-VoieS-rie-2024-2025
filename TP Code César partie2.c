// C++ code
//
using namespace std;


int key;
int operation = 8;
String mot = "";

void chiffrement(int key, String mot)
{
  	//if(mot != "")

  	int longueur = mot.length();
  
  	for(int i = 0; i < longueur; i++)
    {	
      	char charChar = mot[i];
		int intChar = charChar;
      	intChar += key;
        charChar = intChar;
      	mot[i] = charChar;
      	if(intChar <= 122 && intChar >= 97)
        {
			charChar = intChar;
      		mot[i] = charChar;

        }
        else
        {
        	int c = intChar - 122;
        	intChar = 96 + c;
          	charChar = intChar;
          	mot[i] = intChar;
          	
      	}
    }
  	Serial.print(mot);
  
}

void dechiffrement(int key, String mot)
{
  int longueur = mot.length();
  
  	for(int i = 0; i < longueur; i++)
    {	
      	char charChar = mot[i];
		int intChar = charChar;
      	intChar -= key;
        charChar = intChar;
      	mot[i] = charChar;
      	if(intChar <= 122 && intChar >= 97)
        {
			charChar = intChar;
      		mot[i] = charChar;

        }
        else
        {
        	intChar += 26;
          	charChar = intChar;
          	mot[i] = intChar;
          	
      	}
    }
  	Serial.print(mot);
}




void setup()
{
    Serial.begin(9600);
}




void loop()
{	
  	String mot = "";
  
  	int b = 0;
  
  	char readChar = 0; 
  
  	int buff = Serial.available();
  	
  	while(buff > 0) // tant qu'il reste un caractere
    {
      
      	
    	int charn = Serial.read();//lecture du caractere
		char cara = charn;
      	mot += cara;
        delay(10);
    	buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
  
 
	if(mot != "")
    {
      	  	
      
    }
 
	int motai = mot.length();
  	int virgule = mot.indexOf(",", 2);
  	
  
    int key = mot.substring(2,virgule).toInt();

      
    if(mot.substring(0,1).toInt() == 0)
  	{
      	chiffrement(key, mot.substring(virgule+1));
  	}
  	if(mot.substring(0,1).toInt() == 1)
    {
      	dechiffrement(key, mot.substring(virgule+1));
    }
  	
}
