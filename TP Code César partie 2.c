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
  int intChar = readChar + key;
  if(intChar > 122)
  {
    intChar += 26;
  }
  
  readChar = intChar;
  Serial.print(readChar);
  
  buff = Serial.available();
}


String dechiffrement(int buff)
{
  int intChar = readChar - key;
  if(intChar <= 96)
  {
    intChar -= 26;
  }
  
  readChar = intChar;
  Serial.print(readChar);
  
  buff = Serial.available();
}
