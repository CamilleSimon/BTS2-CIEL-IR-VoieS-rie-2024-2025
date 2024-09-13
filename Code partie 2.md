```C++
int key;
int comparaison;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String inputMessage = "";
    while (Serial.available() > 0) {
      char receivedChar = Serial.read();
      inputMessage += receivedChar;
      delay(10);
    }

    if (inputMessage.length() >= 5) {
      if (inputMessage[0] != '0' && inputMessage[0] != '1') {
        Serial.println("Erreur : valeur d'opération invalide. Utilisez 0 pour chiffrement ou 1 pour déchiffrement.");
        return;
      }

      int virgule1 = inputMessage.indexOf(',');
      int virgule2 = inputMessage.indexOf(',', virgule1 + 1);

      if (virgule2 == -1) {
        Serial.println("Erreur : format de message invalide.");
        return;
      }

      String keyString = inputMessage.substring(virgule1 + 1, virgule2);
      key = keyString.toInt();

      String caractere = inputMessage.substring(virgule2 + 1);

      comparaison = inputMessage[0] - '0';

      if (comparaison == 0) {
        chiffrement(key, caractere);
      } else if (comparaison == 1) {
        dechiffrement(key, caractere);
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
    char chiffrementcar = caractere[i] + key;

    if (chiffrementcar > 'z') {
      chiffrementcar = 'a' + (chiffrementcar - 'z' - 1);
    }
    Serial.print(chiffrementcar);
  }
  Serial.println();
}

void dechiffrement(int key, String caractere) {
  for (int i = 0; i < caractere.length(); i++) {
    char dechiffrementcar = caractere[i] - key;

    if (dechiffrementcar < 'a') {
      dechiffrementcar = 'z' - ('a' - dechiffrementcar - 1);
    }
    Serial.print(dechiffrementcar);
  }
  Serial.println();
}

```
