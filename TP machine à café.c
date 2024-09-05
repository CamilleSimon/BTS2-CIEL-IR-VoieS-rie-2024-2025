// C++ code
//
void setup(){
  	Serial.begin(9600);
}

const int totalcharge = 10;
int cafe = totalcharge;
int chocolatchaud = totalcharge;
int the = totalcharge;
const int LUMIERE[] = {13, 12, 11};
bool messagedemande = false;

void allumer(int Led){
	pinMode(Led, OUTPUT);
    digitalWrite(Led, LOW);
}

void loop(){
  	int buff = 0;
  	if (messagedemande == false){
  		Serial.print("Choisissez : cafe, chocolat chaud, the \n");
      	Serial.print("Qauntite :    " + String(cafe) + "        " + String(chocolatchaud) + "         " + String(the) + "\n");
      	messagedemande = true;
  	}
  	else{
    }
  	/*buff = Serial.available();
  	while(buff > 0){
      	char lettre = Serial.read();
  		choix += lettre;
  	}
  	if (choix == "cafe" or choix == "chocolat chaud" or choix == "the"){
  		switch(choix)
          	case "cafe":
      			cafe -= 1;
      			if(cafe < totalcharge / 4){
      				allumer(LUMIERE[0])
                }
                Serial.print("Vous avez selectionner un cafe")
      		case "chocolat chaud":
      			cohcolatchaud -= 1;
      		case "the":
      			the -= 1;
    }
  	else{
    	print("Mauvaise selection veuillez recommencer \n")
        messagedemaned = False
    }*/
}