int key = 0; // déclaration de la clé globale
int comparaison = 0; // déclaration de la clé globale de comparaison 

void setup() {
    Serial.begin(9600); // Initialisation de la communication série
}

void loop() {
    char readChar = 0; // caractère à lire
    int buff = Serial.available(); // Vérifier la disponibilité dans le buffer

    if (buff > 0) { // tant qu'il reste des caractères dans le buffer
        String inputMessage = ""; // Message d'entrée
        while (Serial.available() > 0) {
            readChar = Serial.read(); // lecture du caractère
            inputMessage += readChar; // ajouter au message
            delay(10); // délai pour assurer la lecture complète
        }

        if (inputMessage.length() >= 5) { // Vérifie si la longueur du message est suffisante pour contenir une opération, une clé, et un texte.

            if (inputMessage[0] != '0' && inputMessage[0] != '1') {// Si le premier caractère n'est ni '0' ni '1', affiche un message d'erreur pour l'opération invalide.
                Serial.println("Erreur : valeur d'opération invalide. Utilisez 0 pour chiffrement ou 1 pour déchiffrement.");
                return; 
            }

            int virgule1 = inputMessage.indexOf(','); // Recherche la position de la première virgule
            int virgule2 = inputMessage.indexOf(',', virgule1 + 1); // Recherche la position de la deuxième virgule après la première

            if (virgule2 == -1) { // Si la deuxième virgule n'est pas trouvée, le format est invalide
                Serial.println("Erreur : format de message invalide.");
                return;
            }

            String keyString = inputMessage.substring(virgule1 + 1, virgule2); // Extrait la clé entre les deux virgules
            key = keyString.toInt(); // Conversion de la clé de caractere en entier

            String caractere = inputMessage.substring(virgule2 + 1); // Extrait le texte après la deuxième virgule

            comparaison = inputMessage[0] - '0'; // Obtenez l'opération à partir du premier caractère ('0' pour chiffrement, '1' pour déchiffrement)

            if (comparaison == 0) {
                chiffrement(key, caractere); // Appel à la fonction de chiffrement
            } else if (comparaison == 1) {
                dechiffrement(key, caractere); // Appel à la fonction de déchiffrement
            } else {
                Serial.println("Erreur : action invalide.");
            }
        } else {
            Serial.println("Erreur : format de message invalide.");
        }
    }
}

void chiffrement(int key, String caractere) {
    for (int i = 0; i < caractere.length(); i++) {
        char chiffrementcar = caractere[i] + key; // Ajoute la clé au caractère

        if (chiffrementcar > 'z') {
            chiffrementcar = chiffrementcar - 26; // Si dépasse 'z', revenir à 'a'
        }
        Serial.print(chiffrementcar); // Ecrit le message chiffré
    }
    Serial.println(); 
}

void dechiffrement(int key, String caractere) {
    for (int i = 0; i < caractere.length(); i++) {
        char dechiffrementcar = caractere[i] - key; // Soustrait la clé au caractère

        if (dechiffrementcar < 'a') {
            dechiffrementcar = dechiffrementcar + 26; // Si dépasse 'a', revenir à 'z'
        }
        Serial.print(dechiffrementcar); // Ecrit le message déchiffré
    }
    Serial.println(); 
}

