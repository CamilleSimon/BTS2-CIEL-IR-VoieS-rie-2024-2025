// C++ code
//

String produit[3] = {"cafe","chocolat chaud","the"};
short int stock[3] = { 10,4,1 };
short int pinLed[3] = { 13,12,11 };
short int pinbouton[3] = { 4,3,2 };

void remplir(int type_boisson) {
	stock[type_boisson] = 10;
}




void setup()
{
	Serial.begin(9600);

	for (int i = 0; i < 3; i++) {
		pinMode(pinLed[i], OUTPUT);
		digitalWrite(pinLed[i], HIGH);
		pinMode(pinbouton[i], INPUT);
		digitalWrite(pinbouton[i], HIGH);
	}
}

void loop()
{

      for (int i = 0; i < 3; i++) {
        int etat = digitalRead(pinbouton[i]);
            if (etat == LOW)
                remplir(i);
      }

	  receptionCommande();
  	  checkLumiere();
}


void receptionCommande(){
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); //lire une chaîne complète envoyée

  
    for (int i = 0; i <= 3; i++) {
        if (input == produit[i])
      		servirBoisson(i);
      }
  
      Serial.println(); // Nouvelle ligne pour clarté
  }
  
  
}

void servirBoisson(int type_boisson){
  if (stock[type_boisson] > 0){
  Serial.print("voici votre boisson: ");
  Serial.print(produit[type_boisson]);
  stock[type_boisson]--;
  }else
  {
  Serial.print("Pas de stock disponible");
  }
}
  

void checkLumiere(){
      for (int i = 0; i < 3; i++) {
        short int nbstockpro = stock[i];
        if (stock[i] >= 5){
			digitalWrite(pinLed[i], HIGH);
        }else if (stock[i] < 3){
			digitalWrite(pinLed[i], LOW);
        }else{
        	digitalWrite(pinLed[i], HIGH);
          	delay(450);
          	digitalWrite(pinLed[i], LOW);
		// on peux utiliser digitalWrite(pinLed[i], !digitalRead(pinLed[i])); pour enlever 1 ligne  --> pour optimisé sans ce delat faudrait crée une interruption
        }
      }
  }
