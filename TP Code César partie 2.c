int operation;
int buff;
int key;

void chiffrement(){
    //crypte 
    char readChar = 0;
    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
      	Serial.print("0");
        readChar = Serial.read(); // lecture du caractère
      	if (readChar + key >= 123)
        {
          readChar -= 26;
        }
      	char charcode = readChar + key;
        Serial.print(charcode); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant   
  }
}


void dechiffrement(){
    //décrypte 
    char readChar = 0;
    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
      	if (readChar - key <= 96)
        {
          readChar += 26;
        }
      	char charcode = readChar - key;
        Serial.print(charcode); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant       
    
  }
  
}

void setup()
{
    Serial.begin(9600);
}



void loop()
{
    char readChar = 0; // caractère à lire
    buff = Serial.available();
  
  if (buff > 0){
    operation = Serial.read() -48;
  
    if (operation == 0){
    	chiffrement();
    }else if (operation = 1){
     Serial.print("1");
    }
  }
    
 
}





