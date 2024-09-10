const int COUNT = 3;
const int LEDS[COUNT] = {13, 12, 11};
const int BTNS[COUNT] = {4, 3, 2};
const int LIMIT =2;
const String PRODUITS[COUNT] ={"cafe", "chocolat", "the"};
int stock[COUNT] = {10, 10, 10};
void print(const char* format, ...);
  

void setup()
{
  Serial.begin(9600);
  
  for(int i = 0; i <= COUNT; i++)// initialise les leds et les bouttons
  {
    pinMode(LEDS[i], OUTPUT);
    pinMode(BTNS[i], INPUT);
 	checkLumiere(i);
    digitalWrite(BTNS[i], HIGH);
  }
}


void loop()
{    
  	int buff = 0;
  	char readChar;
 	String s = "";
  	buff = Serial.available();
  	bool trouve = false;
  
  while( buff > 0)
  {
    readChar = Serial.read();
    delay(10);
    s = s + readChar;
    buff = Serial.available();
  }
  	if (s != "")
    {
    	int i = 0; // Déclaration de i avant la boucle while
    
    	while (i < 3 && trouve == false) // Correction : utilisation de && au lieu de ||
    {
      
      	if (PRODUITS[i] == s)
      	{
          	stock[i]--;
            checkLumiere(i);
       		print("La commande est %s, le stock restant de %s est %d", PRODUITS[i].c_str(), PRODUITS[i].c_str(), stock[i]);
          	trouve = true;
      	}
      
      i++; // Incrémentation de i pour parcourir tous les produits
    }

    	if (!trouve) // Ce bloc est exécuté après la boucle si aucun produit n'a été trouvé
    	{
      		print("Commande non valide");
    	}
  	}
  
  for (int i = 0; i < COUNT; i++) 
    {
        if (digitalRead(BTNS[i]) == LOW) // Si le bouton correspondant est pressé
        {
            stock[i] = 10; // Réinitialise le stock à 10
            checkLumiere(i); // Vérifie l'état de la LED après réinitialisation
            print("Reserve de %s reinitialisee a 10", PRODUITS[i].c_str());
            delay(500); // Délai pour éviter des rebonds lors de l'appui du bouton
        }
    }
}



void checkLumiere(int boisson)
{
  if(stock[boisson] <= LIMIT)
  {
    digitalWrite(LEDS[boisson], LOW);// allume la lumiere correspondante
    print("Attention: Le stock de %s est faible (<=25%%)", PRODUITS[boisson].c_str());
  }
  else
  {
  	digitalWrite(LEDS[boisson], HIGH);
  }
} 



/**
 * Affiche sur le moniteur série 
 *
 * char* le message à afficher
 * ...     les données a insérer dans le message
 */
void print(const char* format, ...)
{
  char buffer[512];
  
  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  
  Serial.println(buffer);
}