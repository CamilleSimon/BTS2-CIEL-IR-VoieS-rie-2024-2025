// Définir la clé globale pour le chiffrement
const int key = 6;

void setup() {
  // Initialiser la communication série
  Serial.begin(9600);
}

void loop() {
  // Vérifier si des données sont disponibles dans le buffer série
  if (Serial.available() > 0) {
    // Lire le premier caractère disponible
    char inputChar = Serial.read();
    
    // Vérifier si le caractère est une lettre minuscule
    if (inputChar >= 'a' && inputChar <= 'z') {
      // Ajouter la valeur de la clé au caractère
      char charint = inputChar + key;
      
      // Si le décalage dépasse 'z', le faire revenir au début de l'alphabet
      if (charint > 'z') {
        charint = charint - 26;
      }
      
      // Afficher le caractère chiffré
       inputChar = charint;
      Serial.print(inputChar);
    }
  }
}


