```C++
int pinsled[3]={11,12,13}; // Stockage des valeurs des pins des leds dans un tableau de 3 entiers (11=thé, 12= chocolat, 13=cafe)
int pinsbouton[3]={2,3,4}; // Stockage des valeurs des pins des boutons dans un tableau de 3 entiers (4=cafe, 3=chocolat, 2=the)
int stocks[3]={10,10,10}; // Stockage des valeurs des stocks des boissons dans un tableau de 3 entiers(10=cafe, 10=chocolat, 10=the)
String valide[3]={"cafe","chocolat","the"}; // Stockage des mots valides entré par l'utilisateur dans un tableau de 3 chaîne de caractères

void remplir(int type_boisson)
{
  stocks[type_boisson] = 10;
  Serial.println("Le stock a ete renouvele");
}
String receptionCommande()
{
  String message = Serial.readStringUntil('\n');
  return message;
}
void servirBoisson(int type_boisson)
{
  stocks[type_boisson] = stocks[type_boisson] - 1;
  Serial.println("Votre boisson est servie");
  Serial.println("Stocks restant : ");
  Serial.println(valide[type_boisson] + " : " + stocks[type_boisson]);
    
}
void checkLumiere(int type_boisson)
{
  if(stocks[type_boisson] > 5)
  {
    digitalWrite(pinsled[type_boisson], HIGH);
  }
  else if(stocks[type_boisson] <= 5)
  {
    delay(500);
    digitalWrite(pinsled[type_boisson], HIGH);
    delay(500);
    digitalWrite(pinsled[type_boisson], LOW);
                 
  }
  else
  {
    digitalWrite(pinsled[type_boisson], LOW);
  }
}
void setup()
{
  Serial.begin(9600); // Initialisation de la vitesse de transmission à 9600 bauds
  
  // Initialisation des 3 leds en mode OUTPUT et des 3 boutons en mode INPUT
  pinMode(pinsled[2], OUTPUT);
  pinMode(pinsled[1], OUTPUT);
  pinMode(pinsled[0], OUTPUT);
  pinMode(pinsbouton[2], INPUT);
  pinMode(pinsbouton[1], INPUT);
  pinMode(pinsbouton[0], INPUT);
  
  // Initialisation des 3 leds et des 3 boutons à l'état HIGH
  digitalWrite(pinsled[2], HIGH);
  digitalWrite(pinsled[1], HIGH);
  digitalWrite(pinsled[0], HIGH);
  digitalWrite(pinsbouton[2], HIGH);
  digitalWrite(pinsbouton[1], HIGH);
  digitalWrite(pinsbouton[0], HIGH);
}
// pinsboutons2 = cafe
// pinsbouton1 = chocolat
// pinsbouton0 = the


void loop()
{
  if(Serial.available() > 0)
  {
    String message = receptionCommande();
    if(message == valide[0])
    {
      Serial.println("Preparation de votre " + message);
      servirBoisson(0);
      checkLumiere(0);
    }
    else if(message == valide[1])
    {
      Serial.println("Preparation de votre " + message + " chaud");
      servirBoisson(1);
      checkLumiere(1);
    }
    else if(message == valide[2])
    {
      Serial.println("Preparation de votre " + message);
      servirBoisson(2);
      checkLumiere(2);
    }
    else
    {
      Serial.println("Mauvais choix, les choix sont : cafe, chocolat, the");
    }
    
  }
}
```
