int key;
int operation; /// 0 : le message doit etre chiffre , 1 : le message doit etre dechiffre

void setup()
{
  Serial.begin(9600);
  Serial.println("envoyer un message sous la forme : operation,cle,mot");
}

void loop(){

  int buff = Serial.available();
  char readChar;
  int tab[256];
  int i=0;

  while(buff > 0) {
  readChar = Serial.read();
  tab[i]= readChar;
  i++;
  }

}

String chiffrement(String message)
{
  String messageChiffre;
  for (int i=0;i<message.length(); i++)
  {
    int readChar = message[i]+key;
      if(readChar > 122)
      {
      readChar -= 26;
      }
    char cChar = readChar;
    messageChiffre += cChar;
  }
  Serial.print(messageChiffre);
  return messageChiffre;
}


String dechiffrement(String message)
{
  String messageDechiffre;
  for (int i=0;i<message.length(); i++)
  {
    int readChar = message[i]-key;
      if(readChar < 96)
      {
      readChar += 26;
      }
    char cChar = readChar;
    messageDechiffre += cChar;
  }
  Serial.print(messageDechiffre);
  return messageDechiffre;
}

//substring() indexOf(,)  pour "0,6,bonjour"
