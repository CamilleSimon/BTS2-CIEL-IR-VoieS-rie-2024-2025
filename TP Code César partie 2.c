int key;
int operation; /// 0 : le mssage doit etre chiffre , 1 : le message doit etre dechiffre

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
    char readChar = message[i]+key;
    messageChiffre += readChar;
    if( messageChiffre > 122)
  {
     messageChiffre -= 26;
  }
  }
  return messageChiffre;
  Serial.print(messageChiffre);
    }
}

String dechiffrement(String message)
{
  String messageDechiffre;
  for (int i=0;i<message.length(); i++)
  {
    char readChar = message[i]+key;
    messageDechiffre += readChar;
    if(messageDechiffre < 96 )
  {
    messageDechiffre += 26;
  }
  }
  return messageDechiffre;
  Serial.print(messageDechiffre);
    }
}
