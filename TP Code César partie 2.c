#define true 1
#define false 0


int key = 6;
int operation;
char message;

void setup()
{
    Serial.begin(9600);
}
  
void chiffrement(String message)
{
    for (int i = 0; i < message.length();i++)
    {
      message [i]+=key;
      if (message, charAt(i) > 'z') {
        message[i]-=26;
      Serial.print(message);
      }
      }
}

void dechiffrement(String message)
{
    for (int i = 0; i < message.length();i++)
    {
      message [i]-=key;
      if (message, charAt(i) > 'z') {
        message[i]-=26
      Serial.print(message);
      }
    }
}
  
void loop()
{
  int tab[3][1] = {bool, key, readChar};

  {
    tab[i] = 
    i++;
    String s = "";
  }
  
}
