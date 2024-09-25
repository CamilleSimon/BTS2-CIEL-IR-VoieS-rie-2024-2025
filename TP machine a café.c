const int pinLED[3]={13,12,11};
const int pinBUTTON[3]={4,3,2};
int stock[3]={10,10,10};
char dico[3]={'cafe','chocolat','the'};

void setup()
{
  Serial.begin(9600);
  
  // pour les boutons
pinMode(2, INPUT); // initialise le pin numero 2 comme etant un input
digitalWrite(2, HIGH); // met le pin 2 en etat haut

// pour les leds
pinMode(13, OUTPUT); // initialise le pin numero 13 comme etant un output
digitalWrite(13,  HIGH); // met le pin 13 en etat haut

pinMode(3, INPUT); // initialise le pin numero 3 comme etant un input
digitalWrite(3, HIGH); // met le pin 3 en etat haut

// pour les leds
pinMode(12, OUTPUT); // initialise le pin numero 12 comme etant un output
digitalWrite(12, HIGH); // met le pin 12 en etat haut

pinMode(4, INPUT); // initialise le pin numero 4 comme etant un input
digitalWrite(4, HIGH); // met le pin 4 en etat haut

// pour les leds
pinMode(11, OUTPUT); // initialise le pin numero 11 comme etant un output
digitalWrite(11,  HIGH); // met le pin 11 en etat haut
}

void loop()
{

    for (int i =0; i<3; i++)
    {
        if(digitalRead(pinBUTTON[i])==LOW)
        remplir(i);

    }
}

void remplir(int type_boisson)
{
    stock[type_boisson]=10;
}

void receptionCommande()
{
    char readChar = 0;
  	int buff = Serial.available();
    String commande="";
    int i = 0;
    while (i < buff)
    {
        readChar = Serial.read();
        commande+=readChar;
        
    }
       
        for (int i =0; i<3; i++)
        {
        	if(commande==dico[i])
        	Serial.print(commande);
        }
    
}

void servirBoisson(int type_boisson)
{
    stock[type_boisson]-=1;
}

void checkLumiere(int type_boisson)
{
    for(int i =0;i<3;i++)
    {
    	if(stock[type_boisson]>=5)
        	digitalWrite(pinLED[i],HIGH);
    	else if (stock[type_boisson]<=2.5)
        	digitalWrite(pinLED[i],LOW);
    	else if(stock[type_boisson]<5 && >2.5)
        	digitalWrite(pinLED[i],LOW);
        	delay(1000);
        	digitalWrite(pinLED[i],HIGH);
        	delay(1000);
        	digitalWrite(pinLED[i],LOW);
        	delay(1000);
        	digitalWrite(pinLED[i],HIGH);
        	delay(1000);
        	digitalWrite(pinLED[i],LOW);
    }

}
