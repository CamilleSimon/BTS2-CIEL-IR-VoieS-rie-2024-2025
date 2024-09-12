int operation = 0;
int key = 0;
char limiter = ',';
String tramFull = "";
String message = "";
String finalMessage = "";

void setup() {
    Serial.begin(9600);
}

void loop() {
    char readChar; // caractère à lire
    int buff = 0;
    tramFull = "";
    operation = 0;
    key = 0;
    message = "";
    finalMessage = "";

    buff = Serial.available();

    while (buff > 0) {
        readChar = Serial.read();
        tramFull += readChar;
        delay(10);
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
    
    if (tramFull != "") {
        int firstlimite = tramFull.indexOf(',');
        int secondelimite = tramFull.indexOf(',', firstlimite + 1);

        operation = tramFull.substring(0, firstlimite).toInt();
        key = tramFull.substring(firstlimite + 1, secondelimite).toInt();
        message = tramFull.substring(secondelimite + 1);

        if (operation == 0) {
            chiffrement();
        } else if (operation == 1) {
            dechiffrement();
        }
    }
}

void chiffrement() {
    char charFinal;
    for (int i = 0; i < message.length(); i++) {
        char charTemp = message[i];
        charFinal = message[i] + key; // Ajout de la cle au caractère
        if (charFinal > 'z') {
            charFinal = (charFinal - 'z' - 1) + 'a';
        }
        finalMessage += charFinal;
    }
    Serial.println("Message chiffré : " + finalMessage);
}

void dechiffrement() {
    char charFinal;
    for (int i = 0; i < message.length(); i++) {
        char charTemp = message[i];
        charFinal = message[i] - key; // Ajout de la cle au caractère
        if (charFinal < 'a') {
            charFinal = (charFinal + 'z' + 1) - 'a';
        }
        finalMessage += charFinal;
    }
    Serial.println("Message dechiffré : " + finalMessage);
}