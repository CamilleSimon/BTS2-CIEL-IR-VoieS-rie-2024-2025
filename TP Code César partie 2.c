int key; 
int jesaispas;
String message = "";
String jesaispas2 = "";
void setup()
{
    Serial.begin(9600);
}

    



//code de la prof 
void chiffrement(String message)
{
  for (int i = 0; i<message.length(); i++)//i parcourt tout le message 
  {
    message[i] = message[i] + key;
  }
  Serial.println(message);
}



void dechiffrement (String message)
{
  for (int i = 0; i<message.length(); i++)//i parcourt tout le message 
  {
    message[i] = message[i] - key;
  }
  Serial.println(message);
}
  
void loop()
{
    char readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
      jesaispas2 = readChar;
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
  jesaispas = jesaispas2[0];
  key = s.substring(2, s.indexOf(',', 2));//il s'arrete a la deuxieme virgule non compris
  message = s.substring(s.indexOf(',', 2)+1,);
  if 
  {
    jesaispas = 0
    
}
  
