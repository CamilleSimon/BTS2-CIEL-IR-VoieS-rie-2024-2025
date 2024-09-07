```
void setup()
{
    Serial.begin(9600);
}

int key = 6;

void loop()
{
    int readChar = 0; // caractère à lire

    int buff = Serial.available();

  	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
      	readChar = Serial.read() + key; 
      	char result = readChar;
      	if(readChar > 'z')
        {
        	result = readChar - 26;
        }
	Serial.print(result);
    buff = Serial.available();
    }
}
```
