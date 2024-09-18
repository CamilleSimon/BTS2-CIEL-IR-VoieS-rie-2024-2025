char operation;
char key = 6;
int readChar;
int buff;
void setup()
{
    Serial.begin(9600);
   	
}

void loop()
{
  
	int Tableau[150];
    int buff = Serial.available();
    char readChar;
    int i=0;
  	String s = "";
  int separ=s.indexOF(',',3)
    
  	buff= s + readChar; 
  	if (s.substring(0)
        {
          ;
        }
  
  	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
      readChar = Serial.read();
      Tableau[i]=readChar;
      i++;
    }
     if (operation == 0 ) 
     {
       dechiffrement(message);
     }
    else 
    {
      chiffrement(message);
    }
}

String chiffrement(String message)
{
  String messagechiffre;
  for(int i=0;i<message.length();i++)
  {
    readChar = message[i]+key ; // lecture du caractère
       if(readChar > 123 )
      {
          readChar -= 26;      
      }
        
        Serial.print(message); // envoi du caractère
       int buff = Serial.available(); // mise à jour du nombre de caratères restant
        char message = 0 ; // caractère à lire
  }
 
}
String dechiffrement(String message)
{
  String messagedechiffre;
  for(int i=0;i<message.length();i++)
  {
   readChar = message[i]+key ; // lecture du caractère
       if(readChar > 96 )
      {
          readChar += 26;      
      }
        
        Serial.print(message); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
        char readChar = 0 ; // caractère à lire
  }
 
}
