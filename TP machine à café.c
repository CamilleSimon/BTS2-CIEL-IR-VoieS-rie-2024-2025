const int LEDS[] = {11, 12, 13};
const int BOUTTON[] = {2, 3, 4};
const int BOISSONS[] = {0, 1, 2};  
int niveauBoissons[] = {0, 0, 0};
const int MAX_BOISSON = 10;

const char* COMMANDES[] = {"the", "cafe", "chocolat"};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(LEDS[i], OUTPUT); 
    pinMode(BOUTTON[i], INPUT);
    digitalWrite(BOUTTON[i], HIGH);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    if (digitalRead(BOUTTON[i]) == LOW) {
      remplir(i);
      delay(200);
    }
  }
  if (Serial.available() > 0) {
    receptionCommande();
  }
  checkLumiere();
}

void remplir(int index) {
  if (niveauBoissons[index] < MAX_BOISSON) {
    niveauBoissons[index] = MAX_BOISSON;
  }
}

void receptionCommande() {
  String commande = Serial.readStringUntil('\n');  
  bool commandeValide = false;
  for (int i = 0; i < 3; i++) {
    if (commande.equals(COMMANDES[i])) {
      servirBoisson(i);
      commandeValide = true;
      break;
    }
  }
  if (!commandeValide) {
    Serial.println("Commande non valide");
  }
  afficherStock(); 
}

void servirBoisson(int boisson) {
  if (niveauBoissons[boisson] > 0) {
    niveauBoissons[boisson]--;
  } else {
    Serial.println("Stock épuisé pour cette boisson");
  }
}

void checkLumiere() {
  for (int i = 0; i < 3; i++) {
    if (niveauBoissons[i] < 3) {
      digitalWrite(LEDS[i], LOW);
    } 
    else if (niveauBoissons[i] >= 3 && niveauBoissons[i] <= 5) {
      digitalWrite(LEDS[i], HIGH);
      delay(500); 
      digitalWrite(LEDS[i], LOW);
      delay(500); 
    } 
    else {
      digitalWrite(LEDS[i], HIGH);
    }
  }
}

void afficherStock() {
  Serial.println("Etat du stock :");
  Serial.print("The : ");
  Serial.println(niveauBoissons[0]);
  Serial.print("Cafe : ");
  Serial.println(niveauBoissons[1]);
  Serial.print("Chocolat : ");
  Serial.println(niveauBoissons[2]);
}
