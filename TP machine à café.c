// C++ code
//
void setup(){
  	Serial.begin(9600);
  	pinMode(13, OUTPUT);
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
  		Serial.print("Choisissez : café, chocolat chaud, thé \n");
      	Serial.print("Qauntité :   " + String(cafe) + "         " + String(chocolatchaud) + "         " + String(the) + "\n");
      	messagedemande = true;
  	}
  	else{
    }
  	/*buff = Serial.available();
  	while(buff > 0){
      	char lettre = Serial.read();
  		choix += lettre;
  	}
  	if (choix == "café" or choix == "chocolat chaud" or choix == "thé"){
  		switch(choix)
          	case "café":
      			cafe -= 1;
      			if(cafe < totalcharge / 4){
      				allumer(LUMIERE[0])
                }
      		case "chocolat chaud":
      			cohcolatchaud -= 1;
      		case "thé":
      			the -= 1;
    }
  	else{
    	print("Mauvaise selection veuillez recommencer \n")
        messagedemaned = False
    }*/
}