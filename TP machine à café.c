const int COUNT = 3;
const int LEDS[COUNT] = {13, 12, 11};
const int BTNS[COUNT] = {4, 3, 2};
const int LIMIT = 2;
const String PRODUITS[COUNT] = {"cafe", "chocolat", "the"};
int stock[COUNT] = {10, 10, 10};

void print(const char* format, ...);
void remplir();
void receptionCommande();
void servirBoisson();
void checkLumiere();

void setup() 
{
    Serial.begin(9600);

    for (int i = 0; i < COUNT; i++) 
    {
        pinMode(LEDS[i], OUTPUT);
        digitalWrite(LEDS[COUNT], HIGH);
        pinMode(BTNS[i], INPUT);
        digitalWrite(BTNS[i], HIGH);
        checkLumiere(i);  // Vérifier l'état initial des LEDs
    }
}

void loop() 
{
    receptionCommande();  // Gérer la commande de boisson

    for (int i = 0; i < COUNT; i++) 
    {
      checkLumiere(i);
      if (digitalRead(BTNS[i]) == LOW) 
      {  // Vérifie si le bouton est appuyé
          remplir(i);  // Remplit la boisson correspondante
          delay(500);  // Petit délai pour éviter les rebonds
      }
    }
}


void remplir(int type_boisson) 
{
    stock[type_boisson] = 10;  // Réinitialiser le stock à 10
    checkLumiere(type_boisson);  // Mettre à jour l'état de la LED après le remplissage
    print("Reserve de %s reinitialisee a 10", PRODUITS[type_boisson].c_str());
}


void receptionCommande() 
{
    String s = "";
    char readChar;
    int buff = Serial.available();

    while (buff > 0) 
    {
        readChar = Serial.read();
        delay(10); // Délai pour éviter de lire des caractères partiels
        s += readChar;
        buff = Serial.available();
    }

    if (s != "") 
    {
        servirBoisson(s);  // Appelle la fonction pour traiter la commande
    }
}

void servirBoisson(String commande) 
{
    bool trouve = false;
    for (int i = 0; i < COUNT; i++) 
    {
        if (PRODUITS[i] == commande) 
        {
            if (stock[i] > 0) 
            {
                stock[i]--;  // Décrémenter le stock
                checkLumiere(i);  // Met à jour la LED en fonction du stock
                print("La commande de %s est validee. Stock restant : %d", PRODUITS[i].c_str(), stock[i]);
            } 
            else 
            {
                print("Desole, la reserve de %s est epuisee.", PRODUITS[i].c_str());
            }
            trouve = true;
            break;
        }
    }

    if (!trouve) 
    {
        print("Commande non valide");
    }
}

// Fonction qui met à jour l'état de la LED selon le stock
void checkLumiere(int type_boisson) {
    if (stock[type_boisson] > 5) {
        // LED OFF
        digitalWrite(LEDS[type_boisson], HIGH);
    }

    if (stock[type_boisson] <= 5 && stock[type_boisson] > 2) {
        // LED ON
        digitalWrite(LEDS[type_boisson], LOW);
        delay(750);
        // LED OFF
        digitalWrite(LEDS[type_boisson], HIGH);
        delay(750);
    }

    if (stock[type_boisson] <= 2) {
        // LED ON
        digitalWrite(LEDS[type_boisson], LOW);
    }
}

/**
 * Affiche sur le moniteur série
 *
 * char* le message à afficher
 * ...     les données a insérer dans le message
 */
void print(const char* format, ...) 
{
    char buffer[512];
  
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
  
    Serial.println(buffer);
}