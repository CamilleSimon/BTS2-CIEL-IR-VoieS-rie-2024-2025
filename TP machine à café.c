
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

void receptionCommande()
{

}

void servirBoisson(int type_boisson)
{
  
}

void checkLumiere(int type_boisson)
{
if(stock_boissons[0]>5)
  digitalWrite(cafe, HIGH);
if(stock_boissons[0]>5 && stock_boissons[0]>2)
  digitalWrite(cafe, LOW);
  delay
  digitalWrite(cafe, HIGH);
  delay
  digitalWrite(cafe, LOW);
  delay
if(stock_boissons[0]<3)
  digitalWrite(cafe, LOW);
    
if(stock_boissons[1]>5)
  digitalWrite(cafe, HIGH);
if(stock_boissons[1]>5 && stock_boissons[0]>2)
  digitalWrite(cafe, LOW);
  delay
  digitalWrite(cafe, HIGH);
  delay
  digitalWrite(cafe, LOW);
  delay
if(stock_boissons[1]<3)
  digitalWrite(cafe, LOW);
}

if(stock_boissons[2]>5)
  digitalWrite(cafe, HIGH);
if(stock_boissons[2]>5 && stock_boissons[0]>2)
  digitalWrite(cafe, LOW);
  delay
  digitalWrite(cafe, HIGH);
  delay
  digitalWrite(cafe, LOW);
  delay
if(stock_boissons[2]<3)
  digitalWrite(cafe, LOW);

void loop()
{
  if(digitalRead(pinBouton[0])==LOW)
    remplir(0);
  if(digitalRead(pinBouton[1])==LOW)
    remplir(1);
  if(digitalRead(pinBouton[2])==LOW)
    remplir(2);
  

}
