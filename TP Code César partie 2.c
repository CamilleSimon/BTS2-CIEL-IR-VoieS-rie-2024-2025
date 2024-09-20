// C++ code
//

int key = 0;       // La clé pour le chiffrement/déchiffrement
int operation = 0; // 0 = Chiffrement, 1 = Déchiffrement

void setup() {
    Serial.begin(9600);  // Initialisation de la communication série
}

void loop() {
    if (Serial.available() > 0) {  // Si des données sont disponibles
        String input = Serial.readString();  // Lire toute la chaîne reçue
        
        // Lire l'opération 
        operation = input.substring(0, 1).toInt();

        // Lire la clé 
        int commaIndex1 = input.indexOf(',');  // Position de la première virgule
        int commaIndex2 = input.indexOf(',', commaIndex1 + 1);  // Position de la deuxième virgule

        key = input.substring(commaIndex1 + 1, commaIndex2).toInt();  // Extraire la clé

        // Lire le message après la deuxième virgule
        String message = input.substring(commaIndex2 + 1);

        // Chiffrer ou déchiffrer selon l'opération
        for (int i = 0; i < message.length(); i++) {
            char lettre = message[i];
            
            if (lettre >= 'a' && lettre <= 'z') {  // Si c'est une lettre minuscule
                if (operation == 0) {  // Chiffrement
                    lettre = lettre + key;
                    if (lettre > 'z') lettre -= 26;  // Boucler dans l'alphabet
                } else {  // Déchiffrement
                    lettre = lettre - key;
                    if (lettre < 'a') lettre += 26;  // revenir en arrière
                }
            }

            Serial.print(lettre);  // Afficher chaque lettre
        }

        Serial.println();  // Nouvelle ligne après l'affichage du message
    }
}
