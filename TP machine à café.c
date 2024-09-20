const char* boissons[3] = {"cafe", "the", "chocolat"};
int stock[3] = {1, 1, 1};  // Chaque boisson commence avec un stock de 10

const int leds[3] = {11, 12, 13};
const int boutons[3] = {2, 3, 4};

int commandeValide = 0;
void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 3; i++) {
        pinMode(leds[i], OUTPUT);         
        pinMode(boutons[i], INPUT_PULLUP);  // Utilisation de INPUT_PULLUP pour éviter les résistances externes
        digitalWrite(leds[i], HIGH);
        digitalWrite(boutons[i], HIGH);

       	checkLumiere(i);
    }
  
}

void loop() {
	Serial.println("Bouton");
  	delay(2000);

    for (int i = 0; i < 3; i++) {
     	checkLumiere(i);  // Vérifie la lumière avant de servir une boisson
        if (digitalRead(boutons[i]) == LOW) {  // Bouton appuyé
            remplir(stock, i);  // Remplir le stock pour la boisson correspondante
            delay(100);  // Délai pour éviter des doubles lectures
          	checkLumiere(i);

        }
    }
    
    Serial.println("Choisir entre chocolat chaud, the ou cafe");
    receptionCommande();
  	delay(1000);
  
}
  

void remplir(int* stock, int type_boisson) {
    stock[type_boisson] = 10;  // Remplir la boisson à 10
    Serial.print("Stock de ");
    Serial.print(boissons[type_boisson]);
    Serial.println(" rempli à 10.");
}

void receptionCommande() {

    String message = "";

    while (Serial.available() > 0) {
        char readChar = Serial.read();
        message += readChar;
        delay(1000);
    }

    if (message.length() > 0) {
        message.trim();  // La méthode trim() permet de retirer les blancs en début et fin de chaîne. Les blancs considérés sont les caractères d'espacement (espace, tabulation, espace insécable, etc.) ainsi que les caractères de fin de ligne (LF, CR, etc.).
        Serial.print("Message: ");
        Serial.println(message);
        servirBoisson(message);
    }
}

void servirBoisson(String message) {
    for (int i = 0; i < 3; i++) {
        if (message.equalsIgnoreCase(boissons[i])) {
            if (stock[i] > 0) {
                stock[i]--;  // Décrémenter le stock
                Serial.print("Service ");
                Serial.println(boissons[i]);
                Serial.print("Il reste en stock : ");
				Serial.println(stock[i]);

            } else {
                Serial.print("Stock epuise pour ");
                Serial.println(boissons[i]);
            }
            return;
        }
    }
    Serial.println("Commande inconnue");
}

void checkLumiere(int type_boisson) {
    int etat = stock[type_boisson];
    if (etat > 5) {  // Plus de 50% de stock
        digitalWrite(leds[type_boisson], HIGH);  // LED éteinte
    } else if (etat <= 5 && etat > 2) {  // Entre 50% et 25% de stock
        for (int i = 0; i < 10; i++) {  // LED clignote
            digitalWrite(leds[type_boisson], HIGH);
            delay(500);
            digitalWrite(leds[type_boisson], LOW);
            delay(500);
        }
    } else {  // Moins de 25% de stock
        digitalWrite(leds[type_boisson], LOW);  // LED allumée en continu
    }
}
