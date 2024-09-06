```C++
int key = 0;
String message = "";

void setup() {
  Serial.begin(9600);  // Démarrer la communication série
}

void loop() {
  if (Serial.available()) {  // Si un message est disponible
    String input = Serial.readStringUntil('\n');  // Lire le message

    
    int operation = input.substring(0, 1).toInt();  // 0 pour chiffrer, 1 pour déchiffrer
    key = input.substring(2, 3).toInt();  // La clé est le deuxième nombre
    message = input.substring(4);  // Le reste est le message

    if (operation == 0) {
      chiffrement();  // Chiffrement
    } else {
      dechiffrement();  // Déchiffrement
    }
  }
}

void chiffrement() {
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    c = c + key;  // Ajouter la clé à la lettre
    Serial.print(c);  // Afficher la lettre chiffrée
  }
  Serial.println();  // Passer à la ligne suivante
}

void dechiffrement() {
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    c = c - key;  // Soustraire la clé à la lettre
    Serial.print(c);  // Afficher la lettre déchiffrée
  }
  Serial.println();  // Passer à la ligne suivante
}
```
