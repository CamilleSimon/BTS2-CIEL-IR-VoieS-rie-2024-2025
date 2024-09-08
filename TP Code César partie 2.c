// Déclaration des variables globales
int operation;   // Stocker le type d'opération (0 pour chiffrer, 1 pour déchiffrer)
int key;         // La clé pour le chiffrement ou déchiffrement
String message;  // Le message à traiter

// Fonction de chiffrement
String chiffrement(String msg, int key) {
    String result = "";
    for (int i = 0; i < msg.length(); i++) {
        char c = msg[i];
        int cesarInt = c + key; // Appliquer la clé de chiffrement
        char cesarChar; // caractère codé en char

        if (cesarInt > 'z') { // Vérifier si dépassement de 'z'
             cesarInt = (cesarInt - 'z' - 1) + 'a'; // Vérifier si dépassement de'z'
        }

        cesarChar = cesarInt;
        result += cesarChar;
    }
    return result;
}

// Fonction de déchiffrement
String dechiffrement(String msg, int key) {
    String result = "";
    for (int i = 0; i < msg.length(); i++) {
        char c = msg[i];
        char cesarInt = c - key; // Appliquer la clé de déchiffrement
        char cesarChar; // caractère codé en char
        
        if (cesarInt < 'a') { // Vérifier si dépassement sous 'a'
            cesarInt = (cesarInt + 'z' + 1) - 'a';
        }

        cesarChar = cesarInt;
        result += cesarChar;
    }
    return result;
}

void setup() {
    // Ouverture de la liaison à une vitesse de 9600 bits par seconde
    Serial.begin(9600);
}

void loop() {
    // Si des données sont disponibles sur le port série
    if (Serial.available() > 0) {
        // Lire la ligne complète depuis le port série
        String input = Serial.readStringUntil('\n'); 
        
        // Parse l'entrée pour extraire l'opération, la clé, et le message via les comma délimiteurs
        int firstComma = input.indexOf(',');  // Trouver la première virgule
        int secondComma = input.indexOf(',', firstComma + 1); // Deuxième virgule

        // Extraire l'opération, la clé, et le message
        operation = input.substring(0, firstComma).toInt();   // 0 ou 1 pour chiffrer/déchiffrer
        key = input.substring(firstComma + 1, secondComma).toInt(); // La clé de décalage
        message = input.substring(secondComma + 1);           // Le message à traiter

        // Appeler chiffrement ou déchiffrement selon l'opération
        String result = "";
        if (operation == 0) {
            result = chiffrement(message, key);
        } else if (operation == 1) {
            result = dechiffrement(message, key);
        }

        // Afficher le résultat
        Serial.println("Message transformer : " + result);
    }

    delay(100); // Petit délai pour éviter une surcharge du port série
}