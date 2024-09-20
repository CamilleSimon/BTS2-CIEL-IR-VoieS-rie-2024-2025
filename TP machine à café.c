const int pinLEDS[] = {11, 12, 13};
const int pinBUTTONS[] = {2, 3, 4};
int stock[] = {10, 10, 10};
String commande[] = {"cafe", "chocolat", "the"};

/*void print(const char* format, ...)
{
  char buffer[512];

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);

  Serial.println(buffer);
}*/
int cafe=3;

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
  digitalWrite(3, HIGH); // met le pin 2 en état haut
  pinMode(3, INPUT); // initialise le pin numéro 3 comme étant un input
  digitalWrite(3, HIGH); // met le pin 3 en état haut
  pinMode(4, INPUT); // initialise le pin numéro 4 comme étant un input
  digitalWrite(4, HIGH); // met le pin 4 en état haut
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop()
{
  if (cafe > 5){
   digitalWrite(13,HIGH);
 }
  else if ((cafe<5)&&(cafe>2)){
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }
  else {
    digitalWrite(13,HIGH);}
}

void remplir(int type_boisson)
{
	stock[type_boisson] = 10;
}

/*void receptionCommande()
{
 commande=Serial.read();
}

void servirBoisson()
{
}

void checkLumiere(int type_boisson)
{
 if (cafe > 5){
   digitalWrite(13,HIGH);
 }
  else if (cafe<=5){
    digitalWrite(13,HIGH);
    delay(2000);
    digitalWrite(13,LOW);
    delay(2000);
  }
  else {
    digitalWrite(13,HIGH);}
}*/
