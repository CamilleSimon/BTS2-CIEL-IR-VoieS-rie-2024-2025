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
  
   if (message.length() < 5) {
    Serial.println("Erreur : le message doit contenir au moins 5 caractères.");
    return;  // Arrêter l'exécution si le message est trop court
  }
  if (message.length() > 1) {
    //Vérifier si l'opération est valide (0 ou 1)
    if (message[0] != '0' && message[0] != '1') {
      Serial.println("Erreur : valeur d'opération invalide. Utilisez 0 pour chiffrement ou 1 pour déchiffrement.");
      
    }

    operation = message[0] - '0';

    // Trouver la position de la deuxième virgule
    int positionDeuxiemeVirgule = message.indexOf(',', message.indexOf(',') + 1);
    if (positionDeuxiemeVirgule == -1) {
      Serial.println("Erreur : format de message invalide.");
     
    }

    // Extraire la clé du message
    String keyString = message.substring(2, positionDeuxiemeVirgule);
    key = keyString.toInt();

    // Vérifier si la clé est valide (entre 1 et 25)
    if (key < 1 || key > 25) {
      Serial.println("Erreur : valeur de clé invalide. La clé doit être entre 1 et 25.");
      
    }

    // Extraire le message à crypter ou à décrypter
    String text = message.substring(positionDeuxiemeVirgule + 1);

    // Valider que le message ne contient que des lettres minuscules
    if (!MessageValide(text)) {
      Serial.println("Erreur : le message contient des caractères interdits. Utilisez uniquement des lettres minuscules (a-z).");

    }

    Serial.print("Message: ");
    Serial.println(message);

    if (operation == 0) {
      chiffrement(key, text);
    } else if (operation == 1) {
      dechiffrement(key, text);
    } else {
      Serial.println("Erreur : rentrez un message valide.");
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
    
    if (charcesar < 'a') {
      charcesar = 'z' - ('a' - charcesar - 1);
    }
    Serial.print(charcesar);
  }
  Serial.println();
}

// Fonction permettant de vérifier si le message ne contient que des lettres minuscules
bool MessageValide(String text) {
  for (int i = 0; i < text.length(); i++) {
    if (text[i] < 'a' || text[i] > 'z') {
      return false;
    }
  }
  return true;
}
