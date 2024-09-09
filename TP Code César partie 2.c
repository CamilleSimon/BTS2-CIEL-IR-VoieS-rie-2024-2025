// C++ code
//
void setup(){
  	Serial.begin(9600);
	
}

String recupsansv(String text) {
    String readchar;
    int i = 0;
    while (text[i] != ',' && sizeof(text) != 0) {
        readchar += text[i];
        i++;
    }
    return readchar;
}

String delrecup(String text, int iteration) {
    for (int i = 0; i < iteration; i++) {
        if (text.length() > 0) {
            text.remove(0, 1);
        }
    }
    return text;
}

void chiffrement(String text, int key) {
    for (int i = 0; i < text.length(); i++) {
        char readchar = text[i];
        int cesar = readchar;
        int cesarkey = cesar + key;
        while (cesarkey > 122) {
            cesarkey -= 26;
        }
        char chiffrer = cesarkey;
        Serial.print(chiffrer);
      	Serial.print("\n");
    }
}

void dechiffrement(String text, int key) {
    for (int i = 0; i < text.length(); i++) {
        char readchar = text[i];
        int cesar = readchar;
        int cesarkey = cesar - key;
        while (cesarkey < 97) {
            cesarkey += 26;
        }
        char chiffrer = cesarkey;
        Serial.print(chiffrer);
      	Serial.print("\n");
    }
}

void loop() {
    String text = "";
    String readchar = "";
    int buff = Serial.available();
    while (buff > 0) {
        char lettre = Serial.read();
        text += lettre;
        buff--;
    }
  	Serial.print(text);
    readchar = recupsansv(text);
    text = delrecup(text, readchar.length());

    if (readchar == "0") {
        readchar = recupsansv(text);
        text = delrecup(text, readchar.length());
        int key = readchar[0] - '0';
        chiffrement(text, key);
    } else if (readchar == "1") {
        readchar = recupsansv(text);
        text = delrecup(text, readchar.length());
        int key = readchar[0] - '0';
        dechiffrement(text, key);
    }
}