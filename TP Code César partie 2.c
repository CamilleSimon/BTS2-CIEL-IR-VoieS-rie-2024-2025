// C++ code
//

int operation;
int key;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
  	operation = Serial.peek();
  	int length = Serial.available();
    int tab[length];
    int i = 0;
    while (i < length)
    {
        tab[i] = Serial.read();

        i++;
      
    }
  	String s="";
    int virgule = s.indexOf(',',2);
    key = s.substring(2,virgule).toInt();
    String readchar = s.substring(virgule);
  
  		if (operation == 0)
		{
          chiffrement(readchar);
        }
		else;
		{
          dechiffrement(readchar);
		}
}

String chiffrement (String readchar)
{
  for (int i = 0; i < readchar.length(); i++)
       {
         readchar[i]+=key;
         if(readchar.charAt(i)>'z')
           readchar[i]-=26;
       }
       Serial.print(readchar);
}

String dechiffrement (String readchar)
{
  for (int i = 0; i < readchar.length(); i++)
       {
         readchar[i]-=key;
         if(readchar.charAt(i)>'z')
           readchar[i]-=26;
       }
       Serial.print(readchar);
}


