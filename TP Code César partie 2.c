int operation = 0; // declaration de la variable globale "operation"
int key = 0; // declaration de la variable globale "key"

void setup()
{
    Serial.begin(9600);
}

void loop()
{
  	String chiffrement(String message)
	{
    	int readChar = 0; // caractère à lire
    	int buff = Serial.available();
    	while(buff > 0) // tant qu'il reste des caractères dans le buffer
    	{    
        	readChar = Serial.read()+key; // lecture du caractère
        	char resultat = readChar; // On stock le caractère obtenu précédemment dans une variable resultat que l'on déclare
        	if(readChar > 'z') // Condition si jamais le caractère ASCII vaut plus de 122 (z)
        	{
          		resultat = readChar-26; // On lui enlève 26 pour revenir à a
        	}

        	Serial.print(resultat); // Affichage du caractère avec ajout de la clé
        	buff = Serial.available(); // mise à jour du nombre de caratères restant
    	}
  		return message;
	}
  
  
  	String dechiffrement(String message)
	{
  		return message;
	}
  
  
    //int operationpos = message.indexOf(','); // index de la premiere virgule
    //int keypos = message.indexOf(',', operationpos + 1 ); // index de la second virgule
    //int taillemot = message.length()-keypos-1; // taille du mot après la seconde virgule
  

  
  //if(operation==0)
  //{
    
  //}
  //if(operation==1)
  //{
    
  //}
}
