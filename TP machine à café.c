// C++ code
//

// La broche numérique 3 est reliée au Bouton. On lui donne le nom Bouton.
String Tab[4] = {"cafe","chocolat","the"};
int pinLED[4] = {13,12,11};
int pinBOUTON[4] = {4,3,2};
int stockBoisson[4] = {10,10,10};

int buff = 0;


// La broche numérique 5 est reliée à la led rouge. On lui donne le nom Ledrouge.


// Déclaration variable EtatBouton qui va servir à stocker une valeur au format bool soit LOW ou HIGH.
//bool EtatBoutonRouge;
//bool EtatBoutonVert;
//bool EtatBoutonJaune;



void setup() {
  // Ouvre le port série à 9600 bps.
  Serial.begin(9600);
  
  // Faire de la broche du Bouton une entrée avec activation de la résistance de rappel interne de l'ARDUINO .
  for (int i = 0; i < 3 ;i++)
  {
  	pinMode(pinBOUTON[i], INPUT);
  }
  
  
  
  // Définit Ledrouge soit la broche numérique 5 comme sortie.
  for (int i = 0; i < 3 ;i++)
  {
  	pinMode(pinLED[i], OUTPUT);
  }
 
  
  //LED ETEINTE
  for (int i = 0; i < 3 ;i++)
  {
  	digitalWrite(pinLED[i],HIGH);
  }

  
  //BOUTON NON PRESSE
  for (int i = 2; i < 5 ;i++)
  {
  	digitalWrite(i,HIGH);
  }
  
}

void loop() 
{
	
  // LES FONCTIONS DES BOUTONS
  
  if (digitalRead(pinBOUTON[0]) == LOW)
  {
    delay(100);	
    remplir(0);
    delay(100);	
  }
  
  if (digitalRead(pinBOUTON[1]) == LOW)
  {
    remplir(1);
    delay(100);	
  }
  
  if (digitalRead(pinBOUTON[2]) == LOW)
  {  
  	remplir(2);
    delay(100);	
  }
	
  receptionCommande();
  
  for (int i = 0; i < 3 ;i++)
  {
  	checkLumiere(i);
  }

  delay(1);
}


void remplir(int type_boisson)
{
  	stockBoisson[type_boisson] = 10;
    Serial.print("Le stock a ete mis a jour ");
  	delay(100);
}

void receptionCommande()
{
	char readChar;
  	int buff = Serial.available();
  	String string1;
  
	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {	
      	delay(10);
    	readChar = Serial.read();
      	
    	string1 = string1 +readChar;
      	buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
  
  	for (int i = 0; i < 3 ;i++)
    {
      if (string1 == Tab[i])
      {

          servirBoisson(i);
      }
    }
  	
  
}

void servirBoisson(int boisson)
{
  	delay(50);
    if (stockBoisson[boisson] > 0)
    {
    	stockBoisson[boisson] = stockBoisson[boisson]-1;
      	Serial.print(" Vous avez bien commande un : ");
      	Serial.print(Tab[boisson]);
      	delay(50);
    }
  	else 
    {
    	Serial.print(" Il n'y a plus de stock de : ");
      	Serial.print(Tab[boisson]);
      	delay(50);
    }
}

void checkLumiere(int type_boisson)
{
  
 
  
  	//LED ROUGE ----------------------------------------------
  	
  
  
	if (stockBoisson[0] <= 5 && stockBoisson[0] > 2)
  	{
      digitalWrite(pinLED[0], HIGH); // Dit au microcontrôleur: Allume la LED Rouge
      delay(500);  				// Dit au microcontrôleur: Attends une seconde
      digitalWrite(pinLED[0], LOW);	// Dit au microcontrôleur: Éteind la LED rouge
      delay(500);  
  	}
  	else if (stockBoisson[0]<3)
    {
      	// Eteint la led jaune car pas 1/4 du stock
    	digitalWrite(pinLED[0], LOW);
    }
  	else
    {
      	// Allume la led rouge car + 3/4 du stock
    	digitalWrite(pinLED[0], HIGH);
    }
  
  
  	
  	//LED JAUNE -------------------------------------------------
  
  
  
    if(stockBoisson[1] <= 5 && stockBoisson[1] > 2)
    {
      digitalWrite(pinLED[1], HIGH); // Dit au microcontrôleur: Allume la LED Rouge
      delay(500);  				// Dit au microcontrôleur: Attends une seconde
      digitalWrite(pinLED[1], LOW);	// Dit au microcontrôleur: Éteind la LED rouge
      delay(500);  
    }
  	else if (stockBoisson[1]<3)
    {
      	// Eteint la led jaune car pas 1/4 du stock
    	digitalWrite(pinLED[1], LOW);
    }
  	else
    {
      	// Allume la led jaune car + 3/4 du stock
    	digitalWrite(pinLED[1], HIGH);
    }
  
  
  
  
  	//LED VERTE -------------------------------------------------
    
  
  
  	if (stockBoisson[2] <= 5 && stockBoisson[2] > 2)
    {
      digitalWrite(pinLED[2], HIGH); // Dit au microcontrôleur: Allume la LED Rouge
      delay(500);  				// Dit au microcontrôleur: Attends une seconde
      digitalWrite(pinLED[2], LOW);	// Dit au microcontrôleur: Éteind la LED rouge
      delay(500);  
    }
  	else if (stockBoisson[2]<3)
    {
      	// Eteint la led verte car pas 1/4 du stock
    	digitalWrite(pinLED[2], LOW);
    }
  	
  	else 
    {
      	// Allume la led verte car + 3/4 du stock
    	digitalWrite(pinLED[2], HIGH);
    }
  
  
}
