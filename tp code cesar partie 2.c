int key, operation, message; // definir une variable

void setup()// crée une fonction
{
  Serial.begin(9600);


}

void loop()// crée une fonction
{ 
  int buff = Serial.available();
  char readChar = 0; // caractère à lire
  String s="";
 
  while(buff > 0)
  {
    readChar=Serial.read();  // lecture du caractère
    s= s + readChar; //rajouter a s le contenu de readChar
    buff=Serial.available(); // mise à jour du nombre de caratères restant
  }
  if (s != "")
  {
  	String stringOne = "0,6,bonjour";
  // substring(index) looks for the substring from the index position to the end:
  Serial.print(stringOne.substring(0,1));
  operation = stringOne.substring(0,1).toInt();
  Serial.print(operation);
  
 

  Serial.print(stringOne.substring(2,4));
  stringOne = "<HTML><HEAD><BODY>";
int lastOpeningBracket = stringOne.lastIndexOf('<');


  // substring(index) looks for the substring from the index position to the end:
  Serial.print(stringOne.substring(4,10));
  Serial.print (s);
  }
  if (operation ==48 )
  {
    chiffrement(s);   
  }
  
  else 
  {
   if (operation==49)
   {
    dechiffrement(s);
   }
  }
}




 void chiffrement(String message)// crée une fonction
{
  for (int i=0; i<message.length(); i++)
  {
    message [i]+=key;
    if(message.charAt(i)>'z')
    message[i]-=26;
  }
    Serial.print(message);
}




 void dechiffrement(String message)// crée une fonction
{
  for (int i=0; i<message.length(); i++)
  {
    message [i]-=key;
    if(message.charAt(i)>'z')
    message[i]+=26;
  }
    Serial.print(message);
}

