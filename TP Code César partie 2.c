int key;
int operation;

void setup() {
  Serial.begin(9600);
}

void loop() {
  String message = "";  
  while (Serial.available() > 0) {  
    char readChar = Serial.read();  
    message += readChar;  
    delay(10);  
  }

  if (message.length() > 1) {  
    operation = message[0] - '0';  
    key = message[2] - '0';  
    Serial.print("Message: ");
    Serial.println(message);  

    if (operation == 0) {
      chiffrement(key, message.substring(4));  
    } else if (operation == 1) {
      dechiffrement(key, message.substring(4));  
    } else {
      Serial.println("Rentrez un message valide  ");
    }
  }
}

void chiffrement(int key, String message) {
  Serial.print("Chiffrement: ");
  for (int i = 0; i < message.length(); i++) {
    char charcesar = message[i] + key;
    
    if (charcesar > 'z') {
      charcesar = 'a' + (charcesar - 'z' - 1);
    }
    Serial.print(charcesar);  
  }
  Serial.println();  
}

void dechiffrement(int key, String message) {
  Serial.print("Dechiffrement: ");
  for (int i = 0; i < message.length(); i++) {
    char charcesar = message[i] - key;
    // Gestion du dépassement pour les lettres en fin d'alphabet
    if (charcesar < 'a') {
      charcesar = 'z' - ('a' - charcesar - 1);
    }
    Serial.print(charcesar);  // Affiche le caractère déchiffré
  }
  Serial.println();  // Nouvelle ligne après le message
}
