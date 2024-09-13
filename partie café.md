```C++
const int ledPins[] = {13, 12, 11};  
const int buttonPins[] = {2, 3, 4}; 
int stockBoissons[] = {10, 10, 10}; 
String commandes[] = {"cafe", "chocolat", "the"};

void setup() {
  Serial.begin(9600); 
  
  for(int i = 0;i<3; i++){
  	pinMode(buttonPins[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }
}

void remplir(int type_boisson){
  stockBoissons[type_boisson] = 10;
}

void receptionCommande() {
  String choix = "";
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();
    choix += receivedChar;
    delay(100); 
  }
  if (choix.length() > 0) {
    int i = 0;
    bool commandeTrouvee = false;
    
    while (i < 3) {
        if (commandes[i] == choix) {
            servirBoisson(i);
            commandeTrouvee = true;
        }
        i++;
    }

    if (!commandeTrouvee) {
        Serial.println("Commande inconnue");
    }
  }
}

void servirBoisson(int type_boisson){
  if (stockBoissons[type_boisson] < 1) {
    Serial.println("Boisson epuisee");
  } else {   
    stockBoissons[type_boisson]--;
    Serial.println("Boisson servie");
  }
}

void loop() {
  receptionCommande();
   for (int i = 0; i < 3; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { 
      remplir(i);
      Serial.println("Stock de " + commandes[i] + " remis à 10.");
      delay(500);
    }
  }
}
```
