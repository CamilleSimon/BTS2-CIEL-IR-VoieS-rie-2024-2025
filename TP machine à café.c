// C++ code
//
void setup(){
  	Serial.begin(9600);
}

const int totalcharge = 10;
int cafe = totalcharge;
int chocolatchaud = totalcharge;
int the = totalcharge;
String choix = "";
const int LUMIERE[] = {13, 12, 11};
bool messagedemande = false;

void allumer(int Led){
	pinMode(Led, OUTPUT);
    digitalWrite(Led, LOW);
}

void loop(){
  	choix = "";
  	int buff = 0;
  	if (messagedemande == false){
  		Serial.print("Choisissez : cafe, chocolat chaud, the \n");
      	Serial.print("Quantite :    " + String(cafe) + "        " + String(chocolatchaud) + "         " + String(the) + "\n");
      	messagedemande = true;
  	}
  	else{
    }
  	buff = Serial.available();
  	while(buff > 0){
      	char lettre = Serial.read();
  		choix += lettre;
      	buff = Serial.available();
  	}
    if (choix == "cafe"){
      	Serial.print("Vous avez selectionner un cafe \n");
      	if (cafe > 0){
      		cafe -= 1;
      		if(cafe < totalcharge / 4){
      			allumer(LUMIERE[0]);
        	}
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
       		if(chocolatchaud < totalcharge / 4){
    			allumer(LUMIERE[1]);
        	}
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
       		if(the < totalcharge / 4){
    			allumer(LUMIERE[2]);
        	}
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
  	else {
  	}
}