// C++ code
//
int pins_led[3] = {13,12,11};
int pins_boutons[3]={4,3,2} ;
int stock_boissons[3] = {10,10,10};
String commandes_valides[3] ={"café","chocolat", "thé"};

void setup()
{
Serial.begin(9600);
// pour les boutons
pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(2, HIGH); // met le pin 2 en état haut
// pour les leds
digitalWrite(12, LOW); // met le pin 13 en état haut
for(int i=0; i<3; i++) 
{
  pinMode(pins_led[i], OUTPUT); // initialise le pin numéro 'i' comme étant un output
  pinMode(pins_boutons[i], INPUT);
}
}

//________________________remplir________________________________________
void remplir(int type_boisson)
{
    stock_boissons[type_boisson]=10;
}
 for(int i=0; i<3; i++){
    if(digitalRead(pins_bouton[i])==LOW)
    remplir(i);
 }
//________________________________________________________________________


void receptionCommande(){

char readChar =0;
int buff = Serial.available();
String commande="";
int i = 0;
    while (i<buff){
        readChar = Serial.read();
        commande+=readChar;
    }
        for (int i=0;i<3; i++){
            if(commande==commandes_valides[i])
            servirBoisson(i);
        }
    }


void servirBoisson(int type_boisson){
    stock_boissons[type_boisson]-=1;
}

void checkLumiere(int type_boisson){
for (int i=11;i<=13; i++){
if(stock_boissons[type_boisson]>=5)
    digitalWrite(i, HIGH);
else if (stock_boissons[type_boisson]<=2.5)
    digitalWrite(i, LOW);
else if(stock_boissons[type_boisson]<5 && > 2.5)
    digitalWrite(i, LOW);
    delay(1000);
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
    delay(1000);
    digitalWrite(i, HIGH);
    delay(1000);
}
}

void loop()
{

}
