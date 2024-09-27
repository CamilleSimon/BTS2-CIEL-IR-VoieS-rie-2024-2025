```C++
int bp[3] = {4,3,2}, led[3] = {13,12,11}, nbrboisson[] = {10,10,10};
String boisson[3] = {"cafe", "chocolat chaud", "the"};

void print(const char* format, ...)
{
  	char buffer[512];

  	va_list args;
  	va_start(args, format);
  	vsprintf(buffer, format, args);
  	va_end(args);

  	Serial.println(buffer);
}

void setup()
{
	Serial.begin(9600);
  	for (int i = 0; i < 3; i++) 
    {
    	pinMode(led[i], OUTPUT);
     	digitalWrite(led[i], HIGH);
    }
  	pinMode(bp[0], INPUT);
  	pinMode(bp[1], INPUT);
   	pinMode(bp[2], INPUT);
  	pinMode(led[0], OUTPUT);
  	pinMode(led[1], OUTPUT);
  	pinMode(led[2], OUTPUT);
  	Serial.println("Tapez le nom de la boisson : 'cafe', 'chocolat chaud', ou 'the'.");
}

void remplir(int type_boisson)
{
	if(digitalRead(bp[type_boisson]) == LOW)
    {
      	nbrboisson[type_boisson] = 10;
    }
}

int receptionCommande()
{
	String sboisson = "";
  	int type_boisson;

	if (Serial.available() > 0) 
    {
        sboisson = Serial.readStringUntil('\n');
        sboisson.trim();

        if (sboisson.equalsIgnoreCase(boisson[0])) 
        {
            if (nbrboisson[0] > 0) 
            {
                print("Vous avez commande un cafe.");
              	return type_boisson = 0;
            } 
          	else 
            {
                print("Désolé, il n'y a plus de cafe disponible.");
            }
        } 
      	
      	else if (sboisson.equalsIgnoreCase(boisson[1])) 
        {
            if (nbrboisson[1] > 0) 
            {
                print("Vous avez commande un chocolat chaud.");
              	return type_boisson = 1;
            } 
          	else 
            {
                print("Désolé, il n'y a plus de chocolat chaud disponible.");
            }
        } 
      	
      	else if (sboisson.equalsIgnoreCase(boisson[2])) 
        {
            if (nbrboisson[2] > 0) 
            {
                print("Vous avez commande un the.");
              	return type_boisson = 2;
            } 
          	else 
            {
                print("Désolé, il n'y a plus de the disponible.");
            }
        } 
      	else 
        {
            print("Commande non reconnue. Veuillez entrer 'cafe', 'chocolat chaud' ou 'the'.");
        }
    }
}

void servirBoisson(int type_boisson)
{
  	if(nbrboisson[type_boisson] > 0)
    {
		nbrboisson[type_boisson]--;
    }
}

void checkLumiere(int type_boisson)
{
  	if(nbrboisson[type_boisson] > 5)
    {
    	digitalWrite(led[type_boisson], LOW);
    }
  	else if((nbrboisson[type_boisson] < 5) && (nbrboisson[type_boisson] > 2.5))
    {
    	for(int i = 1; i > 0; i++)
        {
        	digitalWrite(led[type_boisson], HIGH);
          	delay(1000);
          	digitalWrite(led[type_boisson], LOW);
          	delay(1000);
        }
    }
  	else if(nbrboisson[type_boisson] < 2.5)
    {
    	digitalWrite(led[type_boisson], HIGH);
    }
}


void loop()
{
	receptionCommande();
	servirBoisson(receptionCommande());
  	checkLumiere(receptionCommande());
  	if((bp[0] == LOW) || (bp[1] == LOW) || (bp[2] == LOW))
    {
  		remplir(receptionCommande());
    }
}
```
