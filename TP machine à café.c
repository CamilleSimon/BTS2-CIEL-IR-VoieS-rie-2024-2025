// C++ code

const int LEDS[] = {11, 12, 13};
const int BOUTTON[] = {2, 3, 4};


int boissons[3] = {0, 0, 0};
const int MAX_BOISSON = 10;

const char* Commandes[] = {"the", "cafe", "chocolat"};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(LEDS[i], OUTPUT); 
  }
  for (int i = 0; i < 3; i++) {
    pinMode(BOUTTON[i], INPUT);
    digitalWrite(BOUTTON[i],HIGH);
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
  if (boissons[index] < MAX_BOISSON) {
    boissons[index] = MAX_BOISSON;
  }
}

void receptionCommande() {
  String commande = Serial.readStringUntil('\n');  
  if (commande == Commandes[0]) {
    servirBoisson(0);
  }
  else if (commande == Commandes[1]) {
    servirBoisson(1); 
  }
  else if (commande == Commandes[2]) {
    servirBoisson(2);
  }
  else {
    Serial.println("Commande non valide");
  }
  afficherStock(); 
}

void servirBoisson(int boisson) {
  if (boissons[boisson] > 0) {
    boissons[boisson]--;
  }
}

void checkLumiere() {
  for (int i = 0; i < 3; i++) {
    if (boissons[i] < 3) {
      digitalWrite(LEDS[i], LOW);
    } 
    else if (boissons[i] >= 3 && boissons[i] <= 5) {
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
  Serial.println(boissons[0]);
  Serial.print("Cafe : ");
  Serial.println(boissons[1]);
  Serial.print("Chocolat : ");
  Serial.println(boissons[2]);
}
