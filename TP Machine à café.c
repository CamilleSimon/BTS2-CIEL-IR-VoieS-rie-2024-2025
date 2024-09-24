int tabLED[3] = {13,12,11};
int tabBut[3] = {4,3,2};
int tabStock[3] = {1,1,1};
String tabDico[3] = {"cafe","chocolat chaud","the"};

void print(const char* format, ...)
{
  char buffer[512];

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);

  Serial.println(buffer);
}

void setup()
{
  Serial.begin(9600);
  pinMode(tabBut[0], INPUT);
  digitalWrite(tabBut[0], HIGH);
  pinMode(tabBut[1], INPUT);
  digitalWrite(tabBut[1], HIGH);
  pinMode(tabBut[2], INPUT);
  digitalWrite(tabBut[2], HIGH);
  pinMode(tabLED[0], OUTPUT);
  digitalWrite(tabLED[0], HIGH);
  pinMode(tabLED[1], OUTPUT);
  digitalWrite(tabLED[1], HIGH);
  pinMode(tabLED[2], OUTPUT);
  digitalWrite(tabLED[2], HIGH);
}

void remplir(int type_boisson)
{
    tabStock[type_boisson] = 10;
}

void receptionCommande()
{
  String s = "";
  String commande = "";
  int num;
  char c;
  int buffer = Serial.available();
  while(buffer > 0)
  {
    c = Serial.read();
    s += c;
    delay(10);
    buffer = Serial.available();
  }
  if(s == tabDico[0])
  {
    servirBoisson(0);
    if(tabStock[0] >= 0)
  		print("Voici votre cafe, il reste %d cafes", tabStock[0]);
  }
  if(s == tabDico[1])
  {
    servirBoisson(1);
    if(tabStock[1] >= 0)
  		print("Voici votre chocolat, il reste %d chocolats", tabStock[1]);
  }
  if(s == tabDico[2])
  {
    servirBoisson(2);
    if(tabStock[2] >= 0)
  		print("Voici votre the, il reste %d thes", tabStock[2]);
  }
}

void servirBoisson(int type_boisson)
{
  if(tabStock[type_boisson] != 0)
  	tabStock[type_boisson] -= 1;
  else
    Serial.print("Reservoir vide, impossible de servir la boisson");
}

void checkLumiere(int type_boisson)
{
  if(tabStock[type_boisson] > 5)
    digitalWrite(tabLED[type_boisson], HIGH);
  if(tabStock[type_boisson] < 5 && tabStock[type_boisson] > 2)
  {
    digitalWrite(tabLED[type_boisson], LOW);
    delay(200);
    digitalWrite(tabLED[type_boisson], HIGH);
    delay(200);
  }
  if(tabStock[type_boisson] <= 2)
    digitalWrite(tabLED[type_boisson], LOW);
}

void loop()
{
  checkLumiere(0);
  checkLumiere(1);
  checkLumiere(2);
  receptionCommande();
  if(digitalRead(tabBut[0]) == LOW)
  	remplir(0);
  if(digitalRead(tabBut[1]) == LOW)
  	remplir(1);
  if(digitalRead(tabBut[2]) == LOW)
  	remplir(2);
}
