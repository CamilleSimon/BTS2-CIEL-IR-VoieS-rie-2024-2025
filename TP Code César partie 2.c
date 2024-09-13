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

  }

  if (message.length() > 1) {
    operation = message[0] - '0';

    // Trouver la position de la deuxième virgule
    // Cette fonction est utilisé pour trouver la position de la deuxième virgule dans le message de la chaîne.
	int PosotionDeuxiemeVirgule = message.indexOf(',', message.indexOf(',') + 1);

    // Extraire la clé du message
    String keyString = message.substring(2, PosotionDeuxiemeVirgule);
    key = keyString.toInt();

    Serial.print("Message: ");
    Serial.println(message);

    if (operation == 0) {
      chiffrement(key, message.substring(PosotionDeuxiemeVirgule + 1));
    } else if (operation == 1) {
      dechiffrement(key, message.substring(PosotionDeuxiemeVirgule + 1));
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
