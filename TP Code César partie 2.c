int operation;//corespond a la première valeure
int key = 0;


void setup()
{
    Serial.begin(9600);
    int buff_mot = Serial.available();
  
  
  	//demande si le message doit etre chiffrer ou non
    Serial.println("0 : le message doit etre chiffre");
    Serial.println("1 : le message doit etre dechiffre");
  	Serial.println("-----------------------------------------");
    Serial.println("Valeur de la clef ");
    Serial.println("-----------------------------------------");
  	Serial.println("Message ");
    Serial.println("---------------Example---------------");
    Serial.println("0,6,mon_message");
  
  
}

void loop()
{
    char readChar = 0; // caractère à lire
    int buff = Serial.available();
    
  //Initialisation des Variables :
	char tab[256];//création d'un tableau trèes grand 
  				  //car on ne sait pas combien de caractères il y aura
  
  	int i = 0;//initialisation de i a 0
  	
  
  	//On parcour le Buffer
    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
         						  // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      	
      	
      
        //ecriture du caractère du buffeur dans le tableau tab
        tab[i] = readChar; //parcour le tableau pour y ajouter le caractère
      	//Serial.print("Affiche le tablau : ");
        Serial.print(tab[i]);
      	operation = tab[0];
        i++;//incrémantation de i pour parcourir le tableau
      	
     }
  //connaitre le nombre de digits de la clef
  //affectation de la valeur de la clef
  
  
  if(tab[3] == ','){
  	String key = tab[2];
  	int key_int = key.toInt();//permet de convertir un string en entier directement
  	Serial.print(key_int);
  }
  
  /*
  else{
  	String key = tab[3], tab[2];
  	int key_int = key.toInt();//permet de convertir un string en entier directement
  	Serial.print(key_int);
  }
  
  	String a = "1";
  	int key_int = a.toInt();//permet de convertir un string en entier directement
  	Serial.print(key_int);
*/
  /*int dix = tab[2]*10;
  int unit = tab[3];
  //int key = dix + unit;
  Serial.println(dix);
  Serial.println(unit);
  
  //Choix de la fonction Chiffrement ou Dechiffrement
  switch(operation){
  	case '0':
    //Serial.println("Le message va etre chiffrer : ");
    void Chiffrement(int key);
    break;
    
    case '1':
    //Serial.println("Le message va etre dechiffrer : ");
    void Dechiffrement();
    break;
  
  }*/
  
  
  	
}

//nom des fonctions 
//void Chiffrement(keyValuechar, String readChar)
//void Dechiffrement(keyValuechar, String readChar)

void Chiffrement(String message){
  //Serial.println(key);
  char readChar = 0;
  int buff = Serial.available();
	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
      	int numchar = readChar;
		
      	//condition pour touts les caractère dont: DEC + key > 122 
      	if(numchar + key > 122){ 
      		int numcharReset = 'a';
            int reset = (numchar + key) - 122;//calcule le nombre de decalage qu'il reste a effectuer
          	//Serial.println(reset);
            char newcaratere = (numcharReset + reset)-1 ;
          	Serial.print("cesar");
            Serial.print(newcaratere); // envoi du caractère
            buff = Serial.available(); // mise à jour du nombre de caratères restant
        }else{
        char newcaratere = numchar + key ;
        Serial.print("cesar");
        Serial.print(newcaratere); // envoi du caractère
        buff = Serial.available();
             }      
      }
}





