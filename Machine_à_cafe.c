//VARIABLE GLOBALE
const int COUNT = 3;
const int LED[COUNT] = {13, 12, 11};
const int BTNS[COUNT] = {4, 3, 2};
int stock[COUNT]={10,10,10};
const String PRODUITS[COUNT] = {"cafe", "chocolat chaud", "the"};
int produit = -1;

bool boisson_servi=false;



// PROTOTYPE FONCTION

void remplir(int type_boisson);
int receptionCommande();
void servirBoisson();
int checkLumiere(int type_boisson);
void print(const char* format, ...);





// SETUP

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < COUNT; i++) { 
    pinMode(LED[i], OUTPUT); 
    pinMode(BTNS[i], INPUT);  
    digitalWrite(LED[i], HIGH); 
 	digitalWrite(BTNS[i], HIGH);
  }
}


// LOOP
void loop() {
  
  receptionCommande();
  servirBoisson();
  remplir(produit);
  checkLumiere(produit);
}






//FONCTION



   // FONCTION QUI REMPLI LE STOCK DE PRODUIT A 10 LORSQU'ON APPUIE SUR LE BOUTON POUSSOIR

void remplir(int type_boisson){
    
    if (digitalRead(BTNS[produit]) == LOW && produit<3 && produit>=0) {
      stock[produit] = 10;
      print("La reserve de %s est remplie.\n", PRODUITS[produit].c_str());
    }
  }
    

   // FONCTION QUI RECUPERE LE CONTENU DU BUFFER ET COMPARE AVEC LES COMMANDES POSSIBLE

int receptionCommande(){
  
  bool trouve = false;
 
  String S = "";
  char readChar;
  int buff = Serial.available();
  
 while (buff > 0) {
    readChar = Serial.read();
    delay(10);
    S = S + readChar;
    buff = Serial.available();
  }
  
 if (S != "") {
    Serial.println(S.c_str());
    for (int i = 0; i < COUNT && !trouve; i++) {
      if (PRODUITS[i] == S) {
        if (stock[i] > 0) {
          print("Commande valide: %s\n", PRODUITS[i].c_str());
          trouve = true;
          produit = i;
          boisson_servi=true;
          return produit;
        }
        else if (stock[i] == 0){
        	print("Stock epuise pour %s\n", PRODUITS[i].c_str());
        }
      }
    }
    if (!trouve) {
      print("Commande invalide.\n");
      trouve= false;
      produit =3;
      boisson_servi=false;
      return produit;
      
    }
  }
}

    // FONCTION QUI DECREMENTE LE STOCKE DU PRODUIT LORSQU'UNE COMMANDE EST PASSEE

void servirBoisson(){
  
  if(produit<3 && produit>=0 && boisson_servi == true){
	stock[produit]-= 1; 
    print("Il reste %d %s dans le stock.\n", stock[produit], PRODUITS[produit].c_str());
    boisson_servi=false;
  }
}  

    // FONCTION QUI MET A JOUR L'ETAT DE LA LED EN FONCITON DE LA BOISSON PASSE EN PARAMETRE

int checkLumiere(int type_boisson){

    if (stock[produit] > 5){ 
      digitalWrite(LED[produit], HIGH); 
    }
  
  	else 
    {
	  if(stock[produit] <= 5 && stock[produit] > 2)
      {
        digitalWrite(LED[produit], HIGH);
        delay(400);
        digitalWrite(LED[produit],LOW);
        delay(400);
      }
      else 
      {
 	 	digitalWrite(LED[produit],LOW); 
  	  }
    }
}


   // FONCTION QUI PERMET D'AFFICHER LES CARACTERES COMPLEXE LORSQU'ON AFFICHE 
 
void print(const char* format, ...) {
  char buffer[512];
  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  Serial.println(buffer);
}