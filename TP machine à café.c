// C++ code
//
int pins_des_leds[3]={13,12,11} ;
int pins_boutons[3]={4,3,2} ;
int stock_boissons[3]=(10,10,10) ;
string commande_valide[3]=("café", "chocolat", "thé");

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  // pour les boutons
pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(2, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(13, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(13, LOW); // met le pin 13 en état haut
  for(int i=0, i<3, i++)
  {
    pinMode(pins_des_leds[i], OUTPOUT);
    pinMode(pins_bouttons[i], INPUT);
  }
  
  
// remplir (int type de boisson)
void remplir(int type_boissons)
{
  stock_boissons([type_boissons]=10);
}
for (int i=0, i<3, i++)
{
  if(digitalRead(pins_bouttons[i])==LOW)
    remplir(i);
}
  
 
//reception commande
void receptionCommande()
{
  char readChar=0;
  int buff =Serial.available();
  String commande="";
  int i=0;
  while (i< buff)
  {
    readChar = Serial.read();
    commande+=readChar;
  }
  for (int i=0; i<3; i++)
  {
    if (commande==commande_valide[i])
  }
}

//servirboisson
void servirBoisson(int type_boisson)
{
    stock[type_boissons]-=1;
}

}

  
  
                 
void loop()
{
  Serial.begin(9600);
  // pour les boutons
pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(2, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(13, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(13, HIGH); // met le pin 13 en état haut
// pour les boutons
pinMode(3, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(3, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(12, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(12, HIGH); // met le pin 13 en état haut
// pour les boutons
pinMode(4, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(4, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(11, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(11, HIGH); // met le pin 13 en état haut
}
