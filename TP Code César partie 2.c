int operation;     
int key;           
String message;    

String chiffrement(int key, String message) 
{
  String resultat = "";  

  for (int i = 0; i < message.length(); i++) 
  {
    char c = message[i];  
    char charChiffre = (c - 'a' + key) % 26 + 'a'; 
    resultat += charChiffre;  
  }
  return resultat;  
}


String dechiffrement(int key, String message) 
{
  String resultat = "";  

  for (int i = 0; i < message.length(); i++) 
  {
    char c = message[i];  
    char charDechiffre = (c - 'a' - key + 26) % 26 + 'a'; 
    resultat += charDechiffre;  
  }
  return resultat;  
}

void traiterMessage(String data) 
{
  int firstComma = data.indexOf(',');  
  int secondComma = data.indexOf(',', firstComma + 1);  

  operation = data.substring(0, firstComma).toInt();  
  key = data.substring(firstComma + 1, secondComma).toInt();  
  message = data.substring(secondComma + 1);  

  if (operation == 0) 
  {
    
    String messageChiffre = chiffrement(key, message);
    Serial.println("Message chiffre : " + messageChiffre);  
  } 
  else if (operation == 1) 
  {
    String messageDechiffre = dechiffrement(key, message);
    Serial.println("Message dechiffre : " + messageDechiffre); 
  } 
  else 
  {
    Serial.println("Operation invalide !");    
  }
}

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    String data = Serial.readStringUntil('\n');
    
    traiterMessage(data);
  }
}
