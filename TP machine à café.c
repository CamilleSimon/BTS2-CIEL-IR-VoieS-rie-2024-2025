// C++ code
//
const int TOTALCHARGE = 10;
const int POURCENTAGE = TOTALCHARGE / 2;
String choix = "";
const int PIN = 3;
const String BOISSON[PIN] = {"cafe", "chocolat chaud", "the"};
int stocks[PIN] = {10, 10, 10};
const int LUMIERE[PIN] = {13, 12, 11};
const int BOUTON[PIN] = {7, 6, 5};
bool messagedemande = false;

//const regex MOTIFCAFE("^[cç]*[aáàâäãå]*[f]*[eéèêë]*s?$");
//const regex MOTIFCHOCOLATCHAUD("^[cç]*h*[oóòôöõø]*[cç]*[oóòôöõø]*l*[aáàâäãå]*t* *[cç]*h*[aáàâäãå]*[uúùûü]*d*s?$");
//const regex MOTIFTHE("^t*h*[eéèêë]*s?$");

void setup(){
  	Serial.begin(9600);
  	for (int i = 0; i <= PIN; i++){
  		pinMode(LUMIERE[i], OUTPUT);
      	digitalWrite(LUMIERE[i], HIGH);
      	pinMode(BOUTON[i], INPUT);
      	digitalWrite(BOUTON[i], HIGH);
    }
  	Serial.print("Choisissez : cafe, chocolat chaud, the \n");
    Serial.print("Quantite :    " + String(stocks[0]) + "        " + String(stocks[1]) + "         " + String(stocks[2]) + "\n");
    messagedemande = true;
}

void Allumer(int indice){
  	if(stocks[indice] <= POURCENTAGE / 2){
  		digitalWrite(LUMIERE[indice], LOW);
    }
  	else if (stocks[indice] <= POURCENTAGE){
      	if (digitalRead(LUMIERE[indice]) == LOW){
        	(digitalWrite(LUMIERE[indice], HIGH));
          	delay(200);
        }
      	else {
      		(digitalWrite(LUMIERE[indice], LOW));
        	delay(200);
        }
    }
}

int receptionCommande(int buff){
  	choix = "";
  	while(buff > 0){
      	char lettre = Serial.read();
      	delay(10);
  		choix += lettre;
      	buff = Serial.available();
  	}
  	/*}
  	if (regex_match(choix, MOTIFCAFE)) {
    	choix = "cafe"
    }
  	else if (regex_match(choix, MOTIFCHOCOLATCHAUD)) {
    	choix = "chocolat chaud"
    }
  	else if (regex_match(choix, MOTIFTHE)) {
    	choix = "the"
    }*/
  	for (int i = 0; i < PIN; i++){
      	if (choix == BOISSON[i]){
      		return i;
        }
    }
  	Serial.print("Mauvaise selection veuillez recommencer \n");
    messagedemande = false;
  	return -1;
}

void servirBoisson(int indice){
	Serial.print("Vous avez selectionner un " + String(BOISSON[indice]) + " \n");
	if (stocks[indice] > 0){
      	stocks[indice] -= 1;
    }
    else{
      	Serial.print("Il n'y a plus de " + String(BOISSON[indice]) + " ! \n");
    }
    messagedemande = false;
}

void Remplir(int indice){
  	stocks[indice] = 10;
    Serial.print("Le " + String(BOISSON[indice]) +" a ete recharger \n");
    digitalWrite(LUMIERE[indice], HIGH);
    messagedemande = false;
}

void loop(){
  	int buff = 0;
  	if (messagedemande == false){
  		Serial.print("\nChoisissez : cafe, chocolat chaud, the \n");
      	Serial.print("Quantite :    " + String(stocks[0]) + "        " + String(stocks[1]) + "          " + String(stocks[2]) + "\n");
    	messagedemande = true;
  	}
  	buff = Serial.available();
  	if (buff > 0){
  		int indice = receptionCommande(buff);
      	if (indice != -1){
      		servirBoisson(indice);
      	}
    }
  	for (int i = 0; i < PIN; i++){
      	if (stocks[i] <= POURCENTAGE){
        	Allumer(i);
        }
      	if (digitalRead(BOUTON[i]) == LOW){
      		Remplir(i);
        }
    }
}