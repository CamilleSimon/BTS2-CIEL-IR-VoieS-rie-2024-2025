const int COUNT = 3;
const int LEDS[COUNT] = {13, 12, 11};
const int BTNS[COUNT] = {4, 3, 2};
int stock[COUNT] = {10, 10, 10};
const String PRODUITS[COUNT] = {"cafe", "chocolat", "the"};
const int MAX_STOCK = 10;

void print(const char* format, ...);

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < COUNT; i++)
  {
    pinMode(LEDS[i], OUTPUT);
    pinMode(BTNS[i], INPUT);
    digitalWrite(LEDS[i], HIGH);
    digitalWrite(BTNS[i], HIGH);
  }
}

//Remplir le stock des boissons
void remplir (int type_boisson)
{
  stock[type_boisson] = 10;
}

// Réceptionner une commande de boisson
void receptionCommande()
{
   int buff = 0;
  char readChar;
  String s = "";
  buff = Serial.available();
  bool trouve = false;

  while (buff > 0)
  {
    readChar = Serial.read();
    delay(10);
    s = s + readChar;
    buff = Serial.available();
  }

  if (s != "")
  {
     int i = 0;
    while (i < COUNT && !trouve)
    {
      if (PRODUITS[i] == s)
      {
        servirBoisson(i);

        // on appel la fonction servirBoisson car on a trouvé le bonne boisson donnée par l'utilisateur
      }
    i++;
    }
  }
  
}

// Servir une boisson et décrémenter le stock
void servirBoisson(int type_boisson)
{
  stock[type_boisson]--; 
  // stock[type_boisson] = stock[type_boisson] - 2;
  // stock[type_boisson] -= 2;
  print("La commande a ete passee. Le stock est de %d" , stock[type_boisson]);
}

//Verifier les lumieres
void checkLumiere(int type_boisson)
{
  if (stock[type_boisson] > 5)
  {
    digitalWrite(LEDS[type_boisson], HIGH);
  }
  else {
    if (stock[type_boisson] >= 2 && stock[type_boisson] <= 5)
    {
      digitalWrite(LEDS[type_boisson], HIGH);
      delay(100);
      digitalWrite(LEDS[type_boisson], LOW);
      delay(100);

    }
    else
    {
      digitalWrite(LEDS[type_boisson], LOW);
    }
  }
}

void loop()
 // 1. On parcours les boutons
 // 2. Si un bouton a été appuyé, alors on appelle remplir
{
 receptionCommande();

 for(int i = 0; i < COUNT; i++)
 {
     if (digitalRead(BTNS[i]) == LOW) 
    {
        refill(i);
    }
    checkLumiere(i);
    }
} //<= renvoie LOW si le bouton est pressé et HIGH si le bouton n'est pas pressé

void refill(int type_boisson) {
    stock[type_boisson] = 10;
    Serial.print("[Boisson] ");
    Serial.print(PRODUITS[type_boisson]);
    Serial.println(" REFILL");
}



void print(const char* format, ...)
{
  char buffer[512];

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);

  Serial.println(buffer);
}