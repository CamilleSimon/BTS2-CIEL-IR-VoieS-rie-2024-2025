const int COUNT = 3; // Définit le nombre de boissons, LEDs et boutons
const int LEDS[COUNT] = { 13, 12, 11 }; // Tableau contenant les pins des LEDs correspondantes aux boissons
const int BTNS[COUNT] = { 4, 3, 2 }; // Tableau contenant les pins des boutons correspondants aux boissons
String nomBoissons[COUNT] = { "cafe", "chocolat", "the" }; // Noms des boissons disponibles
int stockboissons[COUNT] = { 0, 0, 0 }; // Tableau contenant les stocks initiaux de chaque boisson

void print(const char* format, ...); // Déclaration de la fonction print pour afficher des messages sur le moniteur série
void stock(int* stockboissons, ...); // Déclaration de la fonction stock (non utilisée dans le code actuel)

void setup()
{
    Serial.begin(9600); // Initialise la communication série à 9600 bauds

    for (int i = 0; i < COUNT; i++) // Boucle pour initialiser les LEDs et les boutons
    {
        pinMode(LEDS[i], OUTPUT); // Définit les pins des LEDs comme sorties
        pinMode(BTNS[i], INPUT_PULLUP); 
        digitalWrite(LEDS[i], HIGH); // Éteint toutes les LEDs au démarrage
    }
}

void loop()
{
    int buff = 0; // Variable pour stocker le nombre de caractères disponibles dans le buffer série
    char readChar; // Variable pour stocker le caractère lu depuis le port série
    String s = ""; // Chaîne pour accumuler les caractères reçus
    buff = Serial.available(); // Vérifie combien de caractères sont disponibles dans le buffer

    while (buff > 0) // Tant qu'il y a des caractères disponibles
    {
        readChar = Serial.read(); // Lit un caractère du port série
        delay(10); // Petit délai pour éviter les lectures incorrectes
        s = s + readChar; // Ajoute le caractère lu à la chaîne
        buff = Serial.available(); // Met à jour le nombre de caractères disponibles
    }

    if (s != "") // Si une commande a été reçue
    {
        bool v = false; // Indicateur pour vérifier si une commande valide a été trouvée
        int i = 0; // Index pour parcourir les tableaux de boissons et stocks

        while (!v && i < COUNT) // Boucle jusqu'à trouver une commande valide ou parcourir toutes les boissons
        {
            if (s == nomBoissons[i]) // Vérifie si la commande reçue correspond à une boisson
            {
                if (stockboissons[i] > 0) // Vérifie si le stock de la boisson est disponible
                {
                    stockboissons[i]--; // Décrémente le stock de la boisson
                    print("Commande valide: %s. Stock restant: %d\n", nomBoissons[i].c_str(), stockboissons[i]); // Affiche la commande valide et le stock restant
                }
                else
                {
                    print("Stock epuise pour %s\n", nomBoissons[i].c_str()); // Affiche un message indiquant que le stock est épuisé pour cette boisson
                }
                v = true; // Indique que la commande a été trouvée et traitée
            }
            i++; // Passe à la boisson suivante
        }

        if (!v) // Si aucune commande valide n'a été trouvée après avoir parcouru toutes les boissons
        {
            print("Commande non valide\n"); // Affiche un message indiquant que la commande est invalide
        }
    }
  
for (int i = 0; i < COUNT; i++) 
{
    if (stockboissons[i] > 3) 
    {
        digitalWrite(LEDS[i], HIGH); // LED allumée, stock faible
    } 
    else 
    {
        digitalWrite(LEDS[i], LOW); // LED éteinte, stock suffisant
    }
}
for (int i = 0; i < COUNT; i++) 
  {
    if (digitalRead(BTNS[i]) == LOW )
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

/**
 * Affiche sur le moniteur série
 *
 * char* format - le message à afficher (avec un formatage optionnel)
 * ... - les données à insérer dans le message
 */
void print(const char* format, ...)
{
    char buffer[512]; // Buffer pour stocker le message formaté

    va_list args; // Liste des arguments supplémentaires
    va_start(args, format); // Initialise la liste des arguments supplémentaires
    vsprintf(buffer, format, args); // Formate le message et le stocke dans le buffer
    va_end(args); // Termine la liste des arguments supplémentaires

    Serial.print(buffer); // Affiche le message formaté sur le moniteur série
}
