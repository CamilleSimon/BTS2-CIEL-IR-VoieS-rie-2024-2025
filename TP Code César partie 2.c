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
  for (int i=0; i<message.lenght(; i++)
       }
       message[i]=message[i]+key;
       }
 Serial.print(message)
       }
       
       
       void dechiffrement (String message)
{
  for (int i=0; i<message.lenght(; i++)
       }
       message[i]=message[i]-key;
       }
 Serial.print(message)
       }
