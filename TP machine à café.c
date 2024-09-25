// C++ code
//
void setup()
{
  // pour les boutons de café
pinMode(5, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(5, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(13, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(13, HIGH); // met le pin 13 en état haut
  
  // pour les boutons de chocolat
pinMode(4, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(4, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(12, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(12, HIGH); // met le pin 13 en état haut
  
  // pour les boutons de thé 
pinMode(3, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(3, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(11, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(11, HIGH); // met le pin 13 en état haut
  
  const int leds[] = {13, 12, 11};
  const int pin[] = {5, 4, 3};
  int stock[] = {10, 10, 10};
  char dico[] = {cafe, chocolat, thé};
}

void loop()
{
  remplir(int type_boisson) 
  {
   type_boisson = 10 
  }
  
  receptionCommande() 
  {
    
  }
  
  servirBoisson(int type_boisson) 
  {
    type_boisson = --
    
  }
  
  checkLumiere(int type_boisson) 
  {
    
  }

}
