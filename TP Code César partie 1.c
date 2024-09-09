// Définir la clé globale pour le chiffrement
int key = 6;

void setup() {
  // Initialiser la communication série
  Serial.begin(9600);
}

void loop() {
  int buff = Serial.available();
  char readChar;

  while (buff > 0) {
    readChar = Serial.read();
    int intChar = readChar + key; // Correction de la casse ici

    // Si le décalage dépasse 'z', le faire revenir au début de l'alphabet
    if (intChar > 122) { // Correction ici (casse)
      intChar -= 26;
    }

    // Afficher le caractère chiffré
    readChar = intChar;
    Serial.print(readChar);

    // Mettre à jour le buffer pour éviter une boucle infinie
    buff = Serial.available();
  }
}