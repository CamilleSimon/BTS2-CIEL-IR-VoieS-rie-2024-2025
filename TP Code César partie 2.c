int operation = 0; // declaration de la variable globale "operation" qui stock soit 1 soit 0
int key = 0; // declaration de la variable globale "key" qui stock la clé du décalage
String message = ""; // declaration de la variable globale "message" pour stocker le message à déchiffrer

void setup()
{
    Serial.begin(9600); // Initialisation de la vitesse de transmission a 9600 bauds
}
	
void chiffrement(String message, int key) // fonction chiffrement qui ne renvois rien et qui prend un message et la clé en parametre
{
	for (int i = 0; i < message.length(); i++) // Boucle for qui s'effectue selon la longueur du message
	{
		char c = message[i] + key; // chiffrement avec la clé
		if (c > 'z') // Condition si jamais le caractère ASCII vaut plus de 122 (z)
	    	{
	      		c = c - 26; // On lui enlève 26 pour revenir à a
	    	}
	        Serial.print(c); // Affichage du caractère après le chiffrement
	}
	Serial.println(); // retour à la ligne
}
  
  
	
void dechiffrement(String message, int key) // fonction déchiffrement qui ne renvois rien et qui prend un message et la clé en parametre
{
	for (int i = 0; i < message.length(); i++) // Boucle for qui s'effectue selon la longueur du message
	{
		char c = message[i] - key; // déchiffrement avec la clé
	    	if (c < 'a') // Condition si jamais le caractère ASCII vaut moins de 97 (a)
	    	{
			c = c + 26; // On lui rajoute 26 pour revenir a la fin de l'alphabet
	    	}
	        Serial.print(c); // Affichage du caractère après le déchiffrement
	}
	Serial.println(); // retour à la ligne
}
void loop() 
{
  if (Serial.available() > 0) // Condition pour savoir s'il y a des caractère à lire
  {
	  String message = Serial.readStringUntil('\n'); // lecture de la ligne entrée jusqu'à la fin avec le caractère \n et stockage dans message
	    
	  int operationpos = message.indexOf(',');    // index de la première virgule
	  int keypos = message.indexOf(',', operationpos + 1 ); // index de la seconde virgule
	
	  if (operationpos > 0 && keypos > 0) // Condition pour savoir si le style du message correspond bien a : x,x,message (au cas ou il n'y est pas d'operation ou de clé)
	  {
		  operation = message.substring(0, operationpos).toInt(); // On donne a la variable operation soit 0 soit 1, avec le début de la fonction "substring" à 0 jusqu'à la position de la première virgule, puis on le convertit en entier
		  key = message.substring(operationpos + 1, keypos).toInt(); // On donne a la variable key la clé entrée par l'utilisateur, on part de la position après la première virgule, jusqu'à la position de la deuxième virgule, puis on le convertit en entier
		  message = message.substring(keypos + 1); // On donne a la variable message le message après la deuxième virgule, jusqu'à la fin du message donc uniquement le message a chiffrer ou déchiffrer, sans convertion car il s'agit déjà d'une chaine de caractere
		  
		  if (operation == 0) // Condition si jamais la variable opération est égale à 0, pour un chiffrement
		  {
			  chiffrement(message, key); // Appel de la fonction chiffrement pour chiffrer le message entré avec la clé
		  } 
		  else if (operation == 1) // Condition si jamais la variable opération est égale à 1, pour un déchiffrement
		  {
			  dechiffrement(message, key); // Appel de la fonction dechiffrement pour dechiffrer le message entré avec la clé
		  }
		  else // Si les deux première conditions ne sont pas remplies (différent de 0 ou 1)
		  {
			  Serial.println("Le chiffre de l'operation est invalide, veuillez entrer 0 ou 1"); // On affiche un message d'erreur
		  }
	  }
  }
}
