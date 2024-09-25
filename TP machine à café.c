// C++ code
//
using namespace std;
int etat;
int pinLed[] {13, 12, 11};
int pinBut[] {4, 3, 2};
int stockBoiss[] {4, 0, 10};
String commValid[] {"cafe", "chocolat", "the"};

void print(const char* format, ...)
{
  char buffer[512];

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);

  Serial.println(buffer);
}

void remplir(int type_boisson)
{
  if(type_boisson == 0)
    stockBoiss[0] = 10;
  if(type_boisson == 1)
    stockBoiss[1] = 10;
  if(type_boisson == 2)
    stockBoiss[2] = 10;
  else
    Serial.println(type_boisson);
  
}

String receptionCommande(String mot)
{
  for(int j = 0; j <=2; j++)
  {
    if(mot == commValid[j])
    {
    	servirBoisson(j);
    }
  }
  
  
  
}

void servirBoisson(int type_boisson)
{
	if(stockBoiss[type_boisson] > 0)
    {
      	stockBoiss[type_boisson] -= 1;
  		Serial.println(stockBoiss[type_boisson]);
    }
  	else
      	Serial.print("stock epuise");
    
}

void checkLumiere(int type_boisson)
{
	if(stockBoiss[type_boisson] >= 5)
      digitalWrite(pinLed[type_boisson], HIGH);
    if(stockBoiss[type_boisson] < 5 && stockBoiss[type_boisson] >= 3)
    {
       digitalWrite(pinLed[type_boisson], HIGH);
       delay(200);
       digitalWrite(pinLed[type_boisson], LOW);
       delay(200);
    }
  	if(stockBoiss[type_boisson] < 3)
      digitalWrite(pinLed[type_boisson], LOW);
      
}


void setup()
{
  	for(int i = 2; i <=4; i++)
    {
		pinMode(i, INPUT);
  		digitalWrite(i, HIGH);
    }
  
  	for(int t = 11; t <= 13; t++)
    {
      pinMode(t, OUTPUT);
      digitalWrite(t, HIGH);
    }
  

}

void loop()
{	
  	for(int b = 0; b <=2; b++)
    {
      etat = digitalRead(pinBut[b]);
      if(etat == LOW)
      	remplir(b);
    }
  
  
  
  	String mot = "";
  	int buff = Serial.available();
  
  	while(buff > 0)
  	{
    	char readChar = Serial.read();
    	mot += readChar;
      	delay(3);
    	buff = Serial.available();
  	}
  	if(mot != "")
		receptionCommande(mot);
  
  	checkLumiere(0);
  	checkLumiere(1);
  	checkLumiere(2);
}





