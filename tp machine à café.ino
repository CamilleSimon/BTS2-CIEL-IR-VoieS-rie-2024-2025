int pinLeds[3]={13,12,11};
    int pinBoutons[3]={4,3,2};
    int stockBoissons[3]={10,10,10};
    String DICTIONNAIRE[3]{"café","chocolat chaud","thé"};

void print(const char* format, ...);
  
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
    //remplir();
    receptionCommande();
    //servirBoisson( );
    //checkLumiere(); 
}

void remplir(int type_boisson) 
{
  stockBoissons[type_boisson]=10;
  
}
  
 
void receptionCommande()
 {
     String s="";

    int buff = Serial.available();

   while(buff > 0) // tant qu'il reste des caractères dans le buffer
   {

    
     if( s ==DICTIONNAIRE[0])
     {
       if(stockBoissons[0]>0)
       servirBoisson[0];
       print("Voici votre cafe, il reste %d cafes", stockBoissons);
 
     }
   
      
     if( s ==DICTIONNAIRE[1])
     {
       if(stockBoissons[1]>0)
       servirBoisson[1];
       print("Voici votre chocolat chaud, il reste %d chocolat chaud", stockBoissons);
     }
      
     if( s ==DICTIONNAIRE[2])
     {
       if(stockBoissons[2]>0)
       servirBoisson[2];
       print("Voici votre the, il reste %d the", stockBoissons);
      }
   } 
}
void servirBoisson(int type_boisson)  
  {
          
          
   
  
  
  
  
  
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
