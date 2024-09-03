// C++ code
//
void setup(){
  	Serial.begin(9600);
	
}

int key = 6;

void loop(){
  	char readchar = 0;
    int buff = 0;
  	buff = Serial.available();
    while(buff > 0){
    	readchar = Serial.read();
    	int cesar = readchar;
    	int cesarkey = cesar + key;
    	while (cesarkey > 122){
    		cesarkey -= 26;
    	}
    	char chiffrer = cesarkey;
    	Serial.print(chiffrer);
    	buff = Serial.available();
	}
}