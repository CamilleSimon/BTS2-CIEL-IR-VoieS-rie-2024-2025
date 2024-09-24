int pinLEDS[3]={13,12,11};
    int pinBOUTONS[3]={4,3,2};
    int stockBOISSONS[3]={10,10,10};
    String DICTIONNAIRE[3]{"café","chocolat chaud","thé"};

  void setup()
  {
  
  
  Serial.begin(9600);
   // pour les boutons
   pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(2, HIGH); // met le pin 2 en état haut
    pinMode(3, INPUT); // initialise le pin numéro 3 comme étant un input
digitalWrite(3, HIGH); // met le pin 3 en état haut
    pinMode(4, INPUT); // initialise le pin numéro 4 comme étant un input
digitalWrite(4, HIGH); // met le pin 4 en état haut

    // pour les leds
pinMode(11, OUTPUT); // initialise le pin numéro 11 comme étant un output
digitalWrite(11, LOW); // met le pin 11 en état haut
pinMode(12, OUTPUT); // initialise le pin numéro 12 comme étant un output
digitalWrite(12, HIGH); // met le pin 12 en état haut    
 pinMode(13, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(13, HIGH); // met le pin 13 en état haut   
    
  
   
  
  }

void loop()
{ 
    remplir()
    receptionCommande()
    servirBoisson(int type_boisson)
    checkLumiere(int type_boisson) 
}

void remplir(int type_boisson) 
{
  stock[type_boisson]=10;
  if(digitalRead
     {
        remplir(0);
     }
}
  
 
void receptionCommande()
 {
     
   char readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {

    readChar = Serial.read(); // lecture du caractère
     if( DICTIONNAIRE[
 }
  
  
void servirBoisson(int type_boisson)  
  {
          
          
   }
  
  
  
  
  
}
