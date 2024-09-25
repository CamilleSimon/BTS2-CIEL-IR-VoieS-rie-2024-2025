
void setup()
{
    Serial.begin(9600);
	
  
   // pour les boutons
pinMode(4, INPUT); // initialise le pin numéro 4 comme étant un input
digitalWrite(4, HIGH); // met le pin 4 en état haut
  
pinMode(3, INPUT); // initialise le pin numéro 3 comme étant un input
digitalWrite(3, HIGH); // met le pin 3 en état haut
  
pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(2, HIGH); // met le pin 2 en état haut
  
  // pour les leds
pinMode(13, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(13, HIGH); // met le pin 13 en état haut
  
pinMode(12, OUTPUT); // initialise le pin numéro 12 comme étant un output
digitalWrite(12, HIGH); // met le pin 12 en état haut
  
pinMode(11, OUTPUT); // initialise le pin numéro 11 comme étant un output
digitalWrite(11, HIGH); // met le pin 11 en état haut
  
  
 // tableaux pour stocker les informations
 const int LEDS[3] = {13,12,11}; // Pin led 
 const int BOUTON[3] = {4,3,2}; // Pin boutons
 const int STOCK[3] = {10,10,10}; // stock 
 const String BOISSON[3] = {café,chocolatchaud,thé}; // dictinoaire valide
  
  
}
void loop()
{

  // Fonction remplir
 void remplir(int type_boisson)
 {
   STOCK[type_boisson}= 10;
 
 }
 //-----        
         
 //Fonction Reception commande         
 char readChar = 0 ; // caractère à lire        
 int buff = Serial.available();        
 void receptionCommande()
 {
   while(buff > 0 ) 
   {
     readChar = Serial.read();// lecture du caractere
     if(readChar == café}
        {
          do fctcafé;
        }
     if(readChar == chocolatchaud}
        {
          do fctchocolat;
        }
     if(readChar == thé}
        {
          do fctthé;
        }
       }
        
 //-------
        
 //Fonction servirBoisson(int type_boisson)
   void servirBoisson(int type_boisson)
 {
   STOCK[type_boisson}-= 1;
 
 }     
 //-----
   
 //Fonction checkLumiere(int type_boisson)
    void checkLumiere(int type_boisson)
     {
     if(STOCK[0]>5)
 	 digitalWrite(cafe, HIGH);
	 if(QTOCK[0]>5 && STOCK[0]>2)
 	
  
     }
   
   

 
         
 
  
  }
  
  
  
  
  
  
  
  
 
  

  
}



