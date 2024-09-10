const int COUNT = 3;
const int LEDS[COUNT] = {13, 12, 11};
const int BTNS[COUNT] = {4, 3, 2};
int stock[COUNT] = {10, 10, 10};
const int LIMIT = 2;
const int LIMIT_CONS = 5;
const String PRODUITS[COUNT] = {"cafe", "chocolat", "the"};

void print(const char* format, ...);

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < COUNT; i++) {
    pinMode(LEDS[i], OUTPUT);
    pinMode(BTNS[i], INPUT_PULLUP);
    checkLumiere(i);
  }
}

void loop() {
  int buff = 0;
  char readChar;
  String s = "";
  buff = Serial.available();
  bool trouve = false;
  
   // Vérifier les pressions de bouton
  for (int i = 0; i < COUNT; i++) {
    if (digitalRead(BTNS[i]) == LOW) { // Vérifier si le bouton est pressé
      stock[i] = 10; // Réinitialiser le stock à 10
      print("Le stock de %s a ete reinitialise a %d", PRODUITS[i].c_str(), stock[i]);
      delay(200); // Rebond du bouton
    }
  }


  while (buff > 0) {
    readChar = Serial.read();
    delay(10);
    s = s + readChar;
    buff = Serial.available();
  }
    
        for(int i=0; i < COUNT ; i++) { // COUNT = 3 
          checkLumiere(i);
          
          }

  if (s != "") {
    int i = 0;
    while (i < COUNT && !trouve) { 
      if (PRODUITS[i] == s && stock[i] > 0) {
        stock[i]--;
        print("La commande est %s, le stock restant de %s est %d", PRODUITS[i].c_str(), PRODUITS[i].c_str(), stock[i]);
        trouve = true;
        checkLumiere(i);
        
      } else if (PRODUITS[i] == s && stock[i] == 0) {
        print("Le produit %s n'est plus disponible pour le moment", PRODUITS[i].c_str());
        trouve = true;
      }
      i++;
    }

    if (!trouve) {
      print("Commande non valide");
    }
  }
}

// Code du clignotement des boissons 

void checkLumiere(int boisson) {
  if (stock[boisson] > LIMIT_CONS){

    digitalWrite(LEDS[boisson], HIGH); 

  }
  //if (stock[boisson] >=25 && boisson <=50) {
  if (stock[boisson] < 5 && stock[boisson] > 2) {

    digitalWrite(LEDS[boisson], LOW); 
    delay(100);                      
    digitalWrite(LEDS[boisson], HIGH);  
    delay(100); 

  }
  if (stock[boisson] <= LIMIT) {

    digitalWrite(LEDS[boisson], LOW); // Allume la LED correspondante
  }
}

void print(const char* format, ...) {
  char buffer[512];

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);

  Serial.println(buffer);
}

