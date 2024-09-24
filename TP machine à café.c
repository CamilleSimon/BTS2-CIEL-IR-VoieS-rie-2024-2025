
// C++ code
//
int cafe=13;
int chocolat_chaud=12;
int the=11;
int bouton1=4;
int bouton2=3;
int bouton3=2;
String commandesValides[3]={"cafe","chocolat_chaud","the"};
  int pinLED[3]={13,12,11};  
  int pinBouton[3]={4,3,2};  
  int stock_boissons[3]={10,10,10};  

void setup()
{
  
Serial.begin(9600);
pinMode(cafe, OUTPUT);
digitalWrite(cafe, LOW);
pinMode(chocolat_chaud, OUTPUT);
digitalWrite(chocolat_chaud, HIGH);
pinMode(the, OUTPUT);
digitalWrite(the, HIGH);
  
}

void remplir(int type_boisson)
{
	stock_boissons[type_boisson]=10;
}

void loop()
{
  if(digitalRead(pinBouton[0])==LOW)
    remplir(0);
  
  
}
