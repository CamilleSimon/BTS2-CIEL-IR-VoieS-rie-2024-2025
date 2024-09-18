// C++ code
//

int operation;
int key;
void setup()
{
  Serial.begin(9600);
  String s="nkrru";
  key=6;
    dechiffrement(s);

}
  
void loop()
{
  char readChar =0;
  int chiffrement;
  int dechiffrement;
  
  int buff = Serial.available();
  
  String s="";
  while(buff > 0) 
  {
  readChar = Serial.read();
  s += readChar;
  buff = Serial.available();
  }
  Serial.print(s);

}

void chiffrement (String message)
{
  for (int i=0; i<message.length(); i++)
  {
	message[i]=message[i]+key;
    if (message[i]>122)
    {
    	message[i]=message[i]-26;
    }
  }
  Serial.println(message);
}
       
       
       void dechiffrement (String message)
{
  for (int i=0; i<message.length(); i++)
  {
       message[i]=message[i]-key;
    if (message[i]<97){
      message[i]=message[i]+26;
    }
  }
 Serial.print(message);
       }
