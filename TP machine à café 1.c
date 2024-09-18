// C++ code
//



const int ledPin[] = {2, 3, 4};
const int buttonPin[] = {5, 6, 7};
int stock[] = {10, 10, 10};
String commande[] = {"café", "chocolat chaud", "thé"};

void remplir(int type_boisson) {
  stock[type_boisson] = 10;
 
}

void receptionCommande() {
  int buffer = Serial.available();
  if (buffer > 0)
  {
  }
  


}


void setup()
{
   // ouverture de la liaison à une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
    // pour les boutons
pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(2, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(13, INPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(13, HIGH); // met le pin 13 en état haut
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

void loop()
{
 
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
