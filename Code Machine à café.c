
////////////////////////////////////////
// Déclaration des variables globales //
////////////////////////////////////////

const int COUNT = 3;
const int LEDS[COUNT] = { 13, 12, 11 };
const int BTNS[COUNT] = { 4, 3, 2 };
int stockboissons[COUNT] = { 0, 0, 0 };
String nomBoissons[COUNT] = { "cafe", "chocolat", "the" };
String s = "";

//////////////////////
// Fonction fournie //
//////////////////////

/**
 * Affiche sur le moniteur série
 *
 * char* format - le message à afficher (avec un formatage optionnel)
 * ... - les données à insérer dans le message
 */
void print(const char* format, ...)
{
    char buffer[512];

    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    Serial.print(buffer);
}



//////////////////////////////
// Fonctions faites maisons //
//////////////////////////////

// Initialisation des composants
void initializingComponents()
{
    Serial.begin(9600);

    for (int i = 0; i < COUNT; i++)
    {
        pinMode(LEDS[i], OUTPUT);
        pinMode(BTNS[i], INPUT_PULLUP);
        digitalWrite(LEDS[i], HIGH);
    }
}

// Transforme ce qu'il y as dans le buffer en commande
void processingBuffer()
{
    int buff = 0;
    char readChar;
    buff = Serial.available();

    while (buff > 0)
    {
        readChar = Serial.read();
        delay(10);
        s = s + readChar;
        buff = Serial.available();
    }
}

// Traite la commande en fonction du stock
void processingOrder()
{
    if (s != "")
    {
        bool v = false;
        int i = 0;

        while (!v && i < COUNT)
        {
            if (s == nomBoissons[i])
            {
                if (stockboissons[i] > 0)
                {
                    stockboissons[i]--;
                    print("Commande valide: %s. Stock restant: %d\n", nomBoissons[i].c_str(), stockboissons[i]);
                }
                else
                {
                    print("Stock epuise pour %s\n", nomBoissons[i].c_str());
                }
                v = true;
            }
            i++;
        }

        if (!v)
        {
            print("Commande non valide\n");
        }
        s = ""; // Vide S aprés traitement pour éviter que la fonction soit rejouée à chaques loops
    }
}

// Allume la led associée à un produit en fonction de sont stock (-25%)
void checkLowstock()
{
    for (int i = 0; i < COUNT; i++)
    {
        if (stockboissons[i] > 3)
        {
            digitalWrite(LEDS[i], HIGH);
        }
        else
        {
            digitalWrite(LEDS[i], LOW);
        }
    }
}

// Allume la led associée à un produit en fonction de sont stock (entre 50% et 25%)
void checkMediumstock()
{
    for (int i = 0; i < COUNT; i++) {
        if (stockboissons[i] >= 3 && stockboissons[i] <= 5)
        {
            digitalWrite(LEDS[i], HIGH);
            delay(250);
            digitalWrite(LEDS[i], LOW);
            delay(250);
        }
    }
}

// Regroupe les fonctions de vérification du stock
void checkStock()
{
    checkLowstock();
    checkMediumstock();
}

// Recharge le stock d'un produit si pression sur le bouton qui lui est associé
void rechargeStock() 
{
    for (int i = 0; i < COUNT; i++)
    {
        if (digitalRead(BTNS[i]) == LOW)
        {
            if (stockboissons[i] != 10)
            {
                stockboissons[i] = 10;
                delay(100);
                print("%s remplis\n", nomBoissons[i].c_str());
            }
            else
            {
                print("%s deja remplis\n", nomBoissons[i].c_str());
                delay(200);
            }
        }
    }
}


///////////////////////
// Fonctions Arduino //
///////////////////////

void setup()
{
    initializingComponents();
}

void loop()
{
    processingBuffer();
    processingOrder();
    checkStock();
    rechargeStock();
    delay (100);
}