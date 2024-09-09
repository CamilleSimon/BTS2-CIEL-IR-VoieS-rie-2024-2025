// C++ code
//
const int TOTALCHARGE = 10;
const int POURCENTAGE = TOTALCHARGE / 4;
int cafe = TOTALCHARGE;
int chocolatchaud = TOTALCHARGE;
int the = TOTALCHARGE;
String choix = "";
const int PIN = 3;
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
    Serial.print("Quantite :    " + String(cafe) + "        " + String(chocolatchaud) + "         " + String(the) + "\n");
    messagedemande = true;
}

void Allumer(int Led){
    digitalWrite(Led, LOW);
}

void Recharge(int Btnpasc){
  	if (Btnpasc == BOUTON[0]){
  		cafe = 10;
      	Serial.print("Le cafe a ete recharger \n");
      	digitalWrite(LUMIERE[0], HIGH);
      	messagedemande = false;
  	}
  	else if (Btnpasc == BOUTON[1]){
  		chocolatchaud = 10;
      	Serial.print("Le chocolat chaud a ete recharger \n");
      	digitalWrite(LUMIERE[1], HIGH);
      	messagedemande = false;
    }
  	else {
    	the = 10;
      	Serial.print("Le the a ete recharger \n");
      	digitalWrite(LUMIERE[2], HIGH);
      	messagedemande = false;
    }
	digitalWrite(Btnpasc, HIGH);
}

void loop(){
  	choix = "";
  	int buff = 0;
  	if (messagedemande == false){
  		Serial.print("\nChoisissez : cafe, chocolat chaud, the \n");
      	Serial.print("Quantite :    " + String(cafe) + "        " + String(chocolatchaud) + "         " + String(the) + "\n");
      	messagedemande = true;
  	}
  	else{
    }
  	buff = Serial.available();
  	while(buff > 0){
      	char lettre = Serial.read();
      	delay(10);
  		choix += lettre;
      	buff = Serial.available();
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
    if (choix == "cafe"){
      	Serial.print("Vous avez selectionner un cafe \n");
      	if (cafe > 0){
      		cafe -= 1;
        }
      	else{
      		Serial.print("Il n'y a plus de cafe ! \n");
        }
      	messagedemande = false;
    }
    else if (choix == "chocolat chaud"){
      	Serial.print("Vous avez selectionner un chocolat chaud \n");
      	if (chocolatchaud > 0 ){
    		chocolatchaud -= 1;
        }
      	else{
      		Serial.print("Il n'y a plus de chocolat chaud ! \n");
        }
      	messagedemande = false;
    }	
    else if (choix == "the"){
      	Serial.print("Vous avez selectionner un the \n");
      	if (the > 0){
    		the -= 1;
        }
      	else{
      		Serial.print("Il n'y a plus de the ! \n");
        }
      	messagedemande = false;
    }	
  	else if (choix != ""){
    	Serial.print("Mauvaise selection veuillez recommencer \n");
        messagedemande = false;
    }
  	if(cafe <= POURCENTAGE){
    	Allumer(LUMIERE[0]);
    }
    if(chocolatchaud <= POURCENTAGE){
    	Allumer(LUMIERE[1]);
    }
    if(the <= POURCENTAGE){
    	Allumer(LUMIERE[2]);
    }
  	for (int i = 0; i < PIN; i++){
      	if (digitalRead(BOUTON[i]) == LOW){
      		Recharge(BOUTON[i]);
        }
    }
}