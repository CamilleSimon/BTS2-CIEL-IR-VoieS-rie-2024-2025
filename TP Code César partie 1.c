```
//Voici mon code du TP César partie 1

int key = 6;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
  int buff = Serial.available();
  char readChar;

    while(buff > 0)
    {
        readChar = Serial.read();
        
        int intChar = readChar + key;
      
      if(intChar > 122)
      {
        intChar -= 26;
      }
      
      readChar = intChar;
      Serial.print(readChar);
      
      buff = Serial.available();
    }
}
```