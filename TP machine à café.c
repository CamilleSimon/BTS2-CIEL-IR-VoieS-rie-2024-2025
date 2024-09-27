const int pinLEDS[3] = {11, 12, 13}; 
const int pinBUTTONS[3] = {2, 3, 4}; 
int stock[3] = {10, 10, 10};
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

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 3; i++) {
    pinMode(pinLEDS[i], OUTPUT);
    pinMode(pinBUTTONS[i], INPUT_PULLUP);
    digitalWrite(pinLEDS[i], LOW); 
  }
}

void loop()
{
  receptionCommande();
  servirBoisson();
  checkLumiere(type_boisson);
}

void remplir(int type_boisson)
{
	stock[type_boisson] = 10;
}

void receptionCommande()
{
 commande_demande=Serial.read();
  if (commande_demande!=commande) {
    Serial.println("Choisir une boisson valable");
  } else {
    Serial.print("Vous avez choisi : ");
    Serial.println(commande);
  }
}

void servirBoisson(int type_boisson)
{
  if (stock[type_boisson] > 0) {
    stock[type_boisson]--;
  } else {
    Serial.println("Plus en stock");
  }
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
  if (chocolat > 5){
   digitalWrite(12,HIGH);
 }
  else if ((chocolat<5)&&(chocolat>2)){
    digitalWrite(12,HIGH);
    delay(500);
    digitalWrite(12,LOW);
    delay(500);
  }
  else {
    digitalWrite(12,HIGH);}
 if (the > 5){
   digitalWrite(11,HIGH);
 }
  else if ((the<5)&&(the>2)){
    digitalWrite(11,HIGH);
    delay(500);
    digitalWrite(11,LOW);
    delay(500);
  }
  else {
    digitalWrite(11,HIGH);}
}
