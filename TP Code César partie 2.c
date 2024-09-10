int operation = 0;
int key = 0;
char limiter = ',';
String tramFull = "";

void setup() {
    Serial.begin(9600);
}

void loop() {
    char readChar = 0; 
    int buff = 0;
    buff = Serial.available();

    if(buff) {
        readTram();
    }
}

void chiffrement(char readChar, int buff) {
    readChar = Serial.read(); 
    readChar = readChar + key;
    Serial.print(readChar); 
    buff = Serial.available(); 
}

void dechiffrement(char readChar, int buff) {
    readChar = Serial.read(); 
    readChar = readChar - key;
    Serial.print(readChar); 
    buff = Serial.available();
}

void readTram() {
    while(Serial.available()) 
    {
        char readChar;
        int buff;
        readChar = Serial.read(); 
        Serial.println(readChar); 
        tramFull += readChar;
        buff = Serial.available(); 
        Serial.print("TramFull : ");
        Serial.println(tramFull);
        Serial.println("---");
    }
    Serial.println("******** TRAM FINI ********");

    int test = tramFull.find(",");
    Serial.println(test);
}