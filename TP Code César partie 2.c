int key;
int operation;
void setup()
{
  Serial.begin(9600);
}
void chiffrement(String message)
{
  int num;
  for(int i= 0; i < message.length();i++)
  {
  	num = message[i] + key;
  	if(num > 122)
    	num -= 26;
    message[i] = num;
  }
  Serial.print(message);
}

void dechiffrement(String message)
{
  int num;
  for(int i= 0; i < message.length();i++)
  {
  	num = message[i] - key;
  	if(num < 97)
    	num += 26;
    message[i] = num;
  }
  Serial.print(message);
}
void loop()
{
  String s = "";
  String message ="";
  char c;
  int buffer = Serial.available();
  while(buffer > 0)
  {
    c = Serial.read();
    s += c;
    buffer = Serial.available();
  }
  operation = s[0]-'0';
  key = s.substring(2,s.indexOf(',')).toInt();
  message = s.substring(s.indexOf(',',3)+1);
  if(operation == 1)
    dechiffrement(message);
  if(operation == 0)
    chiffrement(message);
}
