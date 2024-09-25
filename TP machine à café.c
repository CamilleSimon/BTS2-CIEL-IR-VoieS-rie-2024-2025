// C++ code
//

const int ledPin[] = {2, 3, 4};
const int buttonPin[] = {5, 6, 7};
int stock[] = {10, 10, 10};
String commandes[] = {"café", "chocolat chaud", "thé"};



void remplir(int type_boisson) 
{
  stock[type_boisson] = 10;
 
}



void receptionCommande() 
{ char readChar = 0;
  int buffer = Serial.available();
  String commande = "";
  int i = 0;
  while (i < buffer)
  {
    readChar = Serial.read();
    commande += readChar;
  }
  for (int i = 0; i < 3; i++)
  {
    if (commande == commande_valide[i])
  }


}

void servirBoisson(int type_boisson)
{
  stock[type_boisson] -= 1;
   
}

void checkLumiere(int type_boisson)
{


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

     
