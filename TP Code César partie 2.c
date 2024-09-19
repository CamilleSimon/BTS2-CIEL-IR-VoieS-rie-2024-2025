int operation;
int key;
String message;

void chiffrement() {
    // Chiffrement du message
    for (int i = 0; i < message.length(); i++) {
        char readChar = message[i];
        
        // Vérifier si le caractère dépasse 'z' après ajout de la clé
        if (readChar + key > 'z') {
            readChar = readChar + key - 26; // Boucler dans l'alphabet
        } else {
            readChar = readChar + key;
        }
        
        Serial.print(readChar); // Affichage du caractère chiffré
    }
    Serial.println(); // Nouvelle ligne pour clarté
}

void dechiffrement() {
    // Déchiffrement du message
    for (int i = 0; i < message.length(); i++) {
        char readChar = message[i];
        
        // Vérifier si le caractère dépasse 'a' après retrait de la clé
        if (readChar - key < 'a') {
            readChar = readChar - key + 26; // Boucler dans l'alphabet
        } else {
            readChar = readChar - key;
        }
        
        Serial.print(readChar); // Affichage du caractère déchiffré
    }
    Serial.println(); // Nouvelle ligne pour clarté
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        // Lire la chaîne entière reçue
        String input = Serial.readStringUntil('\n'); //lire une chaîne complète envoyée
        
        // Diviser la chaîne en parties : opération, clé et message
        int firstComma = input.indexOf(','); // Premier ','
        int secondComma = input.indexOf(',', firstComma + 1); // Deuxième ','
        
        // Extraction des différentes parties
        operation = input.substring(0, firstComma).toInt(); // 0 ou 1
        key = input.substring(firstComma + 1, secondComma).toInt(); // La clé
        message = input.substring(secondComma + 1); // Le message à chiffrer ou déchiffrer
        
        // Exécuter l'opération en fonction du type
        if (operation == 0) {
            chiffrement();  // Chiffrement
        } else if (operation == 1) {
            dechiffrement();  // Déchiffrement
        }
    }
}
