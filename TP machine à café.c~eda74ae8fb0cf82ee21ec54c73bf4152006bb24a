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
    digitalWrite(LEDS[i], LOW);
    digitalWrite(BTNS[i], HIGH);
  }
}

void loop()
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
        if (stock[i] > 0)
        {
          stock[i]--;
          print("La commande est %s, stock restant de %s : %d", PRODUITS[i].c_str(), PRODUITS[i].c_str(), stock[i]);

          updateLedState(i);

        }
        else
        {
          print("Le stock de %s est epuise", PRODUITS[i].c_str());
        }
        trouve = true;
      }
      i++;
    }

    if (!trouve)
    {
      print("Commande non valide");
    }
  }
}

void updateLedState(int produitIndex)
{
  float pourcentageStock = ((float)stock[produitIndex] / MAX_STOCK) * 100;

  if (pourcentageStock > 75)
  {
    digitalWrite(LEDS[produitIndex], LOW);
  }
  else if (pourcentageStock <= 25)
  {
    digitalWrite(LEDS[produitIndex], HIGH);
  }
  else
  {
    digitalWrite(LEDS[produitIndex], LOW);
  }
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