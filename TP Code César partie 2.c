// C++ code
//
void setup(){
  	Serial.begin(9600);
	
}

String recupsansv(String text){
	String readchar;
	int i = 0;
	while(text[i] <> ","){
        	readchar += text[i];
		i++;
	}
	return readchar;
}

String delrecup(String text, int iteration){
	for (int i = 0; i<iteration+1; i++){
		text[0].remove;
	}
}

void chiffrement(String text, int key){
	while(len(text) >= 0){
        	readchar = text[0];
      		int cesar = readchar;
      		int cesarkey = cesar + key;
      		while (cesarkey > 122){
      			cesarkey -= 26;
      		}
      		char chiffrer = cesarkey;
        	print(chiffrer);
	}
}

void dechiffrement(String text, int key){
	while(len(text) >= 0){
        	readchar = text[0];
      		int cesar = readchar;
      		int cesarkey = cesar - key;
      		while (cesarkey < 97){
      			cesarkey += 26;
      		}
      		char chiffrer = cesarkey;
        	print(chiffrer);
	}
}

void loop(){
	String text = "";
  	String readchar = "";
    int buff = 0;
  	buff = Serial.available();
	while(buff > 0){
        text = Serial.read();
	}
	buff = Serial.available();
	readchar = recupsansv(text);
	delrecup(text, len(readchar));
  	if (readchar == "0"){
  		char readchar = "";
      	readchar = recupsansv(text);
		delrecup(text, len(readchar));
      	int key = readchar - 48;
		chiffrement(text, key);
	else if (readchar == "1"){
		char readchar = "";
      	readchar = recupsansv(text);
		delrecup(text, len(readchar));
      	int key = readchar - 48;
		dechiffrement(text, key);
	}
	else{
	}
}