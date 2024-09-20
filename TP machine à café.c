// C++ code
//

//tableaux
int tabpinsBoutton[3] = {4,3,2};//Bouttons
int tabpinsLed[3] = {13,12,11};//LED
String tabComValid[3] = {"cafe", "chocolat chaud", "the"};
int tabStockBoissons[3] = {10,10,10};//Boissons

void setup()
{
  Serial.begin(9600);
  //LED
  pinMode(13, OUTPUT);//LED Rouge
  pinMode(12, OUTPUT);//Jaune
  pinMode(11, OUTPUT);//VERT
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  
  //Boutons
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  digitalWrite(4, HIGH); // met le pin 2 en état haut
  digitalWrite(3, HIGH); // met le pin 2 en état haut
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
      	
  	//Lecture du buffeur
  	receptionCommande(Monitor);
  
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
    
  
	
}

//
void remplir(int type_boisson){
  
  	 if (type_boisson == 1) {
   	 Serial.println("Rechargement du cafe");
     tabStockBoissons[1] = 10;
    } else  if (type_boisson == 2) {
   	 Serial.println("Rechargement du chocolat chaud");
     tabStockBoissons[2] = 10;
    } else if (type_boisson == 3) {
   	 Serial.println("Rechargement du tea");
     tabStockBoissons[3] = 10;
    } 
}

void receptionCommande(String Selection){//récupère le contenu du buffer et compare avec les commandes possible.
  
  	if (Selection == "cafe") {
   	 Serial.println("vous avez selectioné du cafe");
     
    } else  if (Selection == "chocolat chaud") {
   	 Serial.println("vous avez selectioné du chocolat chaud");
     
    } else if (Selection == "the") {
   	 Serial.println("vous avez selectioné du tea");
     
    } 

}

void servirBoisson(){
	
	
  	
  	
}

//servirBoisson()
//checkLumiere(int type_boisson)
