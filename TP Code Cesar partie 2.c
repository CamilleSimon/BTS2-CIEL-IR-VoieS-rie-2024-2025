int key;
int operation;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    String input = Serial.readStringUntil('\n');  // lecture de la ligne envoyer
    processInput(input);  
  }
}

void processInput(String input) 
{
 
  int firstCommaIndex = input.indexOf(',');
  int secondCommaIndex = input.indexOf(',', firstCommaIndex + 1);
  
  if (firstCommaIndex == -1 || secondCommaIndex == -1) 
  {
    Serial.println("Erreur: Format invalide.");  // securiter de format valide
  }
  operation = input.substring(0, firstCommaIndex).toInt();  // recuperer l'opération
  key = input.substring(firstCommaIndex + 1, secondCommaIndex).toInt();  // recuperer la clé
  String message = input.substring(secondCommaIndex + 1);  // recuperer le message
  
  // valide l'operation et la clef
  if (operation < 0 || operation > 1) 
  {
    Serial.println("Erreur: Opération invalide.");
  }
  
  if (key < 1 || key > 25) 
  {
    Serial.println("Erreur: Clé invalide.");
  }
  
  // valide le message
  for (int i = 0; i < message.length(); i++) 
  {
    if (message[i] < 'a' || message[i] > 'z') 
    {
      Serial.println("Erreur: Message invalide.");
    }
  }
  
  // on appel la fonction
  if (operation == 0) 
  {
    chiffrement(message);  // Chiffrement
  } 
  else if (operation == 1) 
  {
    dechiffrement(message);  // Déchiffrement
  }
}

//  chiffrement
void chiffrement(String message)
{
  String result = "";
  for (int i = 0; i < message.length(); i++) 
  {
    char ch = message[i];
    char newChar = ch + key;
    
    if (newChar > 'z') // quand on est au z on retourne au a
    {  
      newChar -= 26;
    }
    
    result += newChar;
  }
  
  Serial.println(result);  // Afficher le message chiffré
}

//  déchiffrement
void dechiffrement(String message) 
{
  String result = "";
  for (int i = 0; i < message.length(); i++) 
  {
    char ch = message[i];
    char newChar = ch - key;
    
    if (newChar < 'a') // quand on est au a on retourne au z
    {  
      newChar += 26;
    }
    
    result += newChar;
  }
  
  Serial.println(result);  // Afficher le message déchiffré
}
