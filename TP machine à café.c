// C++ code
//

//tableaux
int tabpinsBoutton[3] = {4,3,2};//Bouttons
int tabpinsLed[3] = {13,12,11};//LED
String tabComValid[3] = {"cafe", "chocolat chaud", "the"};
int tabStockBoissons[3] = {10,10,10};//Boissons

//---------------------------------------------------------------------------------------------
//src : https://www.youtube.com/watch?v=ybSHrYnxmlY

int temp = 0;//stock la valeur de millis()
			 // millis est une fonction d'arduino qui permet de recup le temps depuis le quel arduino est brancher
const int INTERVAL = 1000; //interval de 1 seconde 
						   //INTERVAL en majsucule car c une constante
int tempActuel = 0;
int tempPrecedant = 0;

int etatLed = LOW;

//---------------------------------------------------------------------------------------------

void setup()
{
  Serial.begin(9600);
  
  //LED
  pinMode(tabpinsLed[0], OUTPUT);//LED Rouge
  pinMode(tabpinsLed[1], OUTPUT);//Jaune
  pinMode(tabpinsLed[2], OUTPUT);//VERT
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  
  //Boutons
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  digitalWrite(4, HIGH); // met le pin 4 en état haut
  digitalWrite(3, HIGH); // met le pin 3 en état haut
  digitalWrite(2, HIGH); // met le pin 2 en état haut
  
}

void loop()
{	
	int i = 0;
    char readChar = 0; // caractère à lire
	String Monitor;
	
  	if (Serial.available() 	> 0){ //condition si le buffeur est vide pour éviter une boucle d'exécution
    	Monitor = Serial.readStringUntil('\n');//permet de recupérrer la saisie du buffer en entier
  		
    }
      	
  	//Lecture du buffer et etat des LED
  	receptionCommande(Monitor);
  	// Appel de checkLumiere pour chaque boisson
    checkLumiere(1); // Café
    checkLumiere(2); // Chocolat chaud
    checkLumiere(3); // Thé
  
  	//Lecture de l'état des boutton poussoir
  	int etat1 = digitalRead(4); // Lire l'état du bouton poussoir
    int etat2 = digitalRead(3); // Lire l'état du bouton poussoir
  	int etat3 = digitalRead(2); // Lire l'état du bouton poussoir
	
     if (etat1 == LOW) {
   	 remplir(1);
    } else  if (etat2 == LOW) {
   	 remplir(2);
    } else if (etat3 == LOW) {
   	 remplir(3);
    } 
  
  //--------------------------------------------------------------------
  /*
  temp = millis();
  //Serial.println(temp);
  
  if (tempActuel - tempPrecedant > INTERVAL){
    if (etatLed == LOW){
    	digitalWrite(tabpinsLed[0], HIGH);
      	etatLed = HIGH;
    }else{
    	digitalWrite(tabpinsLed[0], LOW);
      	etatLed = LOW;
    }
  }
  
  */
  //--------------------------------------------------------------------
  
}

//fonction qui reremplis les boissons du stock a 10
void remplir(int type_boisson){
  
  if (type_boisson == 1) {
   	 Serial.println("Rechargement du cafe");
     tabStockBoissons[0] = 10;
    } 
  else  if (type_boisson == 2) {
   	 Serial.println("Rechargement du chocolat chaud");
     tabStockBoissons[1] = 10;
    } 
  else if (type_boisson == 3) {
   	 Serial.println("Rechargement du tea");
     tabStockBoissons[2] = 10;
    } 
}

//fonction reception de la conmmande, selectione la bonne boissons
void receptionCommande(String Selection){//récupère le contenu du buffer et compare avec les commandes possible.
  
  //pour le cafe :
  if (Selection == "cafe") {
   	 Serial.println("vous avez selectione du cafe");
     	servirBoisson(1);
    }
  //pour le chocolat chaud :
  else  if (Selection == "chocolat chaud") {
   	 Serial.println("vous avez selectione du chocolat chaud");
     	servirBoisson(2);
    }
  //pour le tea :
  else if (Selection == "tea" || Selection == "the") {
   	 Serial.println("vous avez selectione du tea");
     	servirBoisson(3);
    }
	
  
}

//fontion qui Sert les boissons, retrun none 
void servirBoisson(int type_boisson){
  
  //pour le Cafe :
  if (type_boisson == 1 && tabStockBoissons[0] > 0) {
    // verification si le stock des boisson n'est pas a 0
    	Serial.println("Cafe en cours de preparation");
     	tabStockBoissons[0] = tabStockBoissons[0] - 1;
    	//affichage test
     	Serial.println(tabStockBoissons[0]);
  } 
  //pour le chocolat chaud :
  else  if (type_boisson == 2 && tabStockBoissons[1] > 0) {
     // verification si le stock des boisson n'est pas a 0
    	Serial.println("chocolat chaud en cours de preparation");
     	tabStockBoissons[1] = tabStockBoissons[1] - 1;
    	//affichage test
     	Serial.println(tabStockBoissons[1]);
  } 
  //pour le tea :
  else if (type_boisson == 3 && tabStockBoissons[2] > 0) {
     // verification si le stock des boisson n'est pas a 0
    	Serial.println("tea en cours de preparation");
     	tabStockBoissons[2] = tabStockBoissons[2] - 1;
    	//affichage test
     	Serial.println(tabStockBoissons[2]);
  }
  else{
    	Serial.println("ERROR #104");
    	Serial.print("recharger la boisson : ");
    	Serial.print(tabComValid[type_boisson - 1]);
    }
} 
  
//Fonction change l'etat des LED suivant le nombre de boissons quil reste
/*
Éteinte : il reste plus de 50% dans la réserve.
Glignotante : il reste entre 50% et 25% dans la réserve.
Allumée : il reste moins de 25% dans la réserve.
*/
void checkLumiere(int type_boisson){
  
  
  //pour le Cafe :
    if (type_boisson == 1 && tabStockBoissons[0] < 5 && tabStockBoissons[0] > 2) {
    //Serial.println("jkhuilhkuhilhjhl");  
    digitalWrite(tabpinsLed[0], HIGH);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(tabpinsLed[0], LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
  }else if(type_boisson == 1 && tabStockBoissons[0] <= 2 && tabStockBoissons[0] >= 0){
  	digitalWrite(tabpinsLed[0], LOW);
      
  }
  
  //pour le chocolat chaud :
    if (type_boisson == 2 && tabStockBoissons[1] < 5 && tabStockBoissons[1] > 2) {
    digitalWrite(tabpinsLed[1], HIGH);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(tabpinsLed[1], LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
  }else if(type_boisson == 2 && tabStockBoissons[0] <= 2 && tabStockBoissons[1] >= 0){
  	digitalWrite(tabpinsLed[1], LOW);
      
  }
  
  //pour le chocolat tea :
    if (type_boisson == 3 && tabStockBoissons[2] < 5 && tabStockBoissons[2] > 2) {
    digitalWrite(tabpinsLed[2], HIGH);
  	delay(1000); // Wait for 1000 millisecond(s)
  	digitalWrite(tabpinsLed[2], LOW);
  	delay(1000); // Wait for 1000 millisecond(s)
  }else if(type_boisson == 1 && tabStockBoissons[0] <= 2 && tabStockBoissons[2] >= 0){
  	digitalWrite(tabpinsLed[2], LOW);
      
  }
  
}
  	
  	

//servirBoisson()
//checkLumiere(int type_boisson)
