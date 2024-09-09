// ENREGITREMENT DES LEDS
const int pinLedCafe = 13;
const int pinLedChocolat = 12;
const int pinLedThe = 11;

// ENREGITREMENT DES BTNS
const int pinBtnCafe = 4;
const int pinBtnChocolat = 3;
const int pinBtnThe = 2;

// STOCK DES BOISSON
int stockCafe = 10;
int stockChocolat = 10;
int stockThe = 10;

void checkStockCafe();
void checkStockChocolat();
void checkStockThe();

void setup() {
    Serial.begin(9600);

    /* Gestion des LED */
    // CAFÉ
    pinMode(pinLedCafe, OUTPUT);
    checkStockCafe();
    // CHOCOLAT CHAUD
    pinMode(pinLedChocolat, OUTPUT);
    checkStockChocolat();
    // THÉ
    pinMode(pinLedThe, OUTPUT);
    checkStockThe();

    /* Gestion des BOUTON */
    // CAFÉ
    pinMode(pinBtnCafe, INPUT);
    digitalWrite(pinBtnCafe, HIGH);
    // CHOCOLAT CHAUD
    pinMode(pinBtnChocolat, INPUT);
    digitalWrite(pinBtnChocolat, HIGH);
    // THÉ
    pinMode(pinBtnThe, INPUT);
    digitalWrite(pinBtnThe, HIGH);
}

void loop() {
    String tramFull = "";
    char readChar; // caractère à lire
    int buff = 0;

    buff = Serial.available();

    while (buff > 0) {
        readChar = Serial.read();
        tramFull += readChar;
        delay(10);
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }

    if (digitalRead(pinBtnCafe) ==  LOW) {
        stockCafe = 10;
        Serial.println("[Boisson] Cafe RESTOCK");
        checkStockCafe();
    }

    if (digitalRead(pinBtnChocolat) ==  LOW) {
        stockChocolat = 10;
        Serial.println("[Boisson] Chocolat RESTOCK");
        checkStockChocolat();
    }

    if (digitalRead(pinBtnThe) ==  LOW) {
        stockThe = 10;
        Serial.println("[Boisson] The RESTOCK");
        checkStockThe();
    }
    
    if (tramFull != "") {
        if (tramFull == "cafe") {
            if (stockCafe > 0) {
                Serial.println("[Boisson] Cafe choisi");
                // Allume la led red/rouge
                digitalWrite(pinLedCafe, LOW);
                delay(1500);
                checkStockCafe();
                stockCafe--;
            } else {
                Serial.println("[Boisson] Cafe non disponible");
            }
        } else if (tramFull == "chocolat chaud") {
            if (stockChocolat > 0) {
                Serial.println("[Boisson] Chocolat chaud choisi");
                // Allume la led yellow/jaune
                digitalWrite(pinLedChocolat, LOW);
                delay(1500);
                checkStockChocolat();
                stockChocolat--;
            } else {
                Serial.println("[Boisson] Chocolat chaud non disponible");
            }
        } else if (tramFull == "the") {
            if (stockThe > 0) {
                Serial.println("[Boisson] The choisi");
                // Allume la led green/vert
                digitalWrite(pinLedThe, LOW);
                delay(1500);
                checkStockThe();
                stockThe--;

            } else {
                Serial.println("[Boisson] The non disponible");
            }
        } else if (tramFull == "stock") {
            Serial.println("------ STOCK ------");
            Serial.print("Cafe : ");
            Serial.println(stockCafe);
            Serial.print("Chocolat : ");
            Serial.println(stockChocolat);
            Serial.print("The : ");
            Serial.println(stockThe);
            Serial.println("------------------");
        } else {
            Serial.println("------ ERROR ------");
            Serial.println("Boisson non trouver");
            Serial.println("cafe / chocolat chaud / the");
            Serial.println("------------------");
        }
    }
}

void checkStockCafe() {
    if (stockCafe <= 2) {
        digitalWrite(pinLedCafe, LOW);
    } else {
        digitalWrite(pinLedCafe, HIGH);
    }
}

void checkStockChocolat() {
    if (stockChocolat <= 2) {
        digitalWrite(pinLedChocolat, LOW);
    } else {
        digitalWrite(pinLedChocolat, HIGH);
    }
}

void checkStockThe() {
    if (stockThe <= 2) {
        digitalWrite(pinLedThe, LOW);
    } else {
        digitalWrite(pinLedThe, HIGH);
    }
}