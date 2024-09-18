const int COUNT = 3;

// ENREGITREMENT DES LEDS
const int PINLED[3] = {13, 12, 11};

// ENREGITREMENT DES BTNS
const int PINBTN[3] = {4, 3, 2};

// STOCK DES BOISSON
int stock[3] = {10, 4, 1};

String name[3] = {"cafe", "chocolat", "the"};
String tramFull = "";

void refill(int type_boisson);
void receiptOrder();
void serveDrink(int type_boisson);
void checkLight(int type_boisson);

void setup() {
    Serial.begin(9600);

    for (int i = 0; i < COUNT; i++) {
        // LED
        pinMode(PINLED[i], OUTPUT);
        digitalWrite(PINLED[i], HIGH);
        checkLight(i);
        // BTN
        pinMode(PINBTN[i], INPUT);
        digitalWrite(PINBTN[i], HIGH);
    }
}

void loop() {
    char readChar; // caractère à lire
    int buff = 0;
    tramFull = "";

    buff = Serial.available();

    while (buff > 0) {
        readChar = Serial.read();
        tramFull += readChar;
        delay(10);
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
    
    if (tramFull != "") {
        receiptOrder();
    }

    for (int i = 0; i < COUNT; i++) {
        if (digitalRead(PINBTN[i]) == LOW) {
            refill(i);
        }
        checkLight(i);
    }
}

void receiptOrder() {
    bool found = false;
    for (int i = 0; i < COUNT; i++) {
        if (tramFull == name[i]) {
            serveDrink(i);
            found = true;
        }
    }
    if (found == false) {
        Serial.println("------ ERROR ------");
        Serial.println("Boisson non trouver");
        Serial.println("cafe / chocolat chaud / the");
        Serial.println("------------------");
    }
}

void serveDrink(int type_boisson) {
    Serial.print("[Boisson] ");
    Serial.print(name[type_boisson]);
    Serial.println(" choisi");
    stock[type_boisson]--;
}

void checkLight(int type_boisson) {
    if (stock[type_boisson] > 5) {
        digitalWrite(PINLED[type_boisson], HIGH);
    }

    if (stock[type_boisson] <= 5 && stock[type_boisson] > 2) {
        //Serial.print("PINLED[type_boisson] : ");
        //Serial.println(PINLED[type_boisson]);
        digitalWrite(PINLED[type_boisson], LOW);
        delay(500);
        digitalWrite(PINLED[type_boisson], HIGH);
      	delay(500);
    }

    if (stock[type_boisson] <= 2) {
        //Serial.print("PINLED[type_boisson] : ");
        //Serial.println(PINLED[type_boisson]);
        digitalWrite(PINLED[type_boisson], LOW);
    }
}

void refill(int type_boisson) {
    stock[type_boisson] = 10;
    Serial.print("[Boisson] ");
    Serial.print(name[type_boisson]);
    Serial.println(" REFILL");
}