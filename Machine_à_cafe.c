const int COUNT = 3;
const int LED[COUNT] = { 13, 12, 11 };
const int BTNS[COUNT] = { 4, 3, 2 };
int stock[COUNT] = { 10, 10, 10 };
const String PRODUITS[COUNT] = { "cafe", "chocolat chaud", "the" };

void print(const char* format, ...);

void setup() {
    Serial.begin(9600);

    for (int i = 0; i < COUNT; i++) {
        pinMode(LED[i], OUTPUT);
        pinMode(BTNS[i], INPUT);
        digitalWrite(LED[i], HIGH);
        digitalWrite(BTNS[i], HIGH);
    }
}

void loop() {
    bool trouve = false;
    String S = "";
    char readChar;
    int buff = Serial.available();

    while (buff > 0) {
        readChar = Serial.read();
        delay(10);
        S = S + readChar;
        buff = Serial.available();
    }


    // R�initialiser la r�serve si le bouton est appuy�
    for (int k = 0; k < COUNT; k++) {
        if (digitalRead(BTNS[k]) == LOW) {
            stock[k] = 10;
            print("La r�serve de %s est remplie.\n", PRODUITS[k].c_str());
        }
    }

    // Mettre � jour les LEDs en fonction du stock
    for (int j = 0; j < COUNT; j++) {
        if (stock[j] >= 2) {
            digitalWrite(LED[j], HIGH); // LED �teinte si stock > 25%
        }
        else {
            digitalWrite(LED[j], LOW); // LED allum�e si stock < 25%
        }
    }

    // Si une commande est pass�e
    if (S != "") {
        Serial.println(S.c_str());
        for (int i = 0; i < COUNT && !trouve; i++) {
            if (PRODUITS[i] == S) {
                if (stock[i] > 0) {
                    stock[i]--;
                    print("Commande valide: %s\n", PRODUITS[i].c_str());
                    print("Il reste %d %s dans le stock.\n", stock[i], PRODUITS[i].c_str());
                }
                else {
                    print("Stock �puis� pour %s\n", PRODUITS[i].c_str());
                }
                trouve = true;
            }
        }
        if (!trouve) {
            print("Commande invalide.\n");
        }
    }
}


/**
* Affiche sur le moniteur s�rie
*
* char* le message � afficher
* ... les donn�es � ins�rer dans le message
/**/


void print(const char* format, ...) {
    char buffer[512];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    Serial.println(buffer);
}




