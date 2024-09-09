int operation = 0;
int key = 0;
char limiter = ',';
String tramFull = "";

void setup() {
    Serial.begin(9600);
}

void loop() {
    char readChar = 0; // caractère à lire
    int buff = 0;

    buff = Serial.available();

    if(buff) {
        readTram();
    }
}

void chiffrement(char readChar, int buff) {
    readChar = Serial.read(); // lecture du caractère
    readChar = readChar + key;
    Serial.print(readChar); // envoi du caractère
    buff = Serial.available(); // mise à jour du nombre de caratères restant
}

void dechiffrement(char readChar, int buff) {
    readChar = Serial.read(); // lecture du caractère
    readChar = readChar - key;
    Serial.print(readChar); // envoi du caractère
    buff = Serial.available(); // mise à jour du nombre de caratères restant
}

void readTram() {
    while(Serial.available()) // tant qu'il reste des caractères dans le buffer
    {
        char readChar;
        int buff;
        readChar = Serial.read(); // lecture du caractère
        Serial.println(readChar); // envoi du caractère
        tramFull += readChar;
        buff = Serial.available(); // mise à jour du nombre de caratères restant

        Serial.print("TramFull : ");
        Serial.println(tramFull);

        Serial.println("---");
    }
    Serial.println("******** TRAM FINI ********");

    int test = tramFull.find(",");
    Serial.println(test);
}