int key = 0;
int operation = 0;
char message[100];

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');


        int positionPremiereVirgule = input.indexOf(',');
        int positionDeuxiemeVirgule = input.indexOf(',', positionPremiereVirgule + 1);

        operation = input.substring(0, positionPremiereVirgule).toInt();

        key = input.substring(positionPremiereVirgule + 1, positionDeuxiemeVirgule).toInt();

        String texteMessage = input.substring(positionDeuxiemeVirgule + 1);
        texteMessage.toCharArray(message, 100);


        if (operation == 0) {
            chiffrement();
        }
        else if (operation == 1) {
            dechiffrement();
        }
    }
}

void chiffrement() {
    for (int i = 0; i < strlen(message); i++) {
        int charInt = message[i] + key;

        if (charInt > 'z') {
            charInt = charInt - 26;
        }

        message[i] = charInt;
    }

    Serial.println(message);

}

void dechiffrement() {
    for (int i = 0; i < strlen(message); i++) {
        int charInt = message[i] - key;

        if (charInt < 'a') {
            charInt = charInt + 26;
        }

        message[i] = charInt;
    }

    Serial.println(message);
}