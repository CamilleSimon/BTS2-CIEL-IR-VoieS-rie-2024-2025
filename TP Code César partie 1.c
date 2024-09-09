// Variable globale d'encryptage
int key = 6;

// C++ code
//
void setup()
{
  // Ouverture de la liaison à une vitesse de 9600 bits par seconde.
  Serial.begin(9600);
}

void loop()
{	
    char readChar; // caractère à lire
    int cesarInt; // caractère codé en int
  	char cesarChar; // caractère codé en char
    String message = "";
    String messageCoder = "";

    while (Serial.available() > 0) // Tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // Lecture du caractère

        // Appliquer le chiffrement de César avec un décalage de 6
        cesarInt = readChar + key; 

        // Vérifier si CesarChar dépasse 'z' (ASCII 122)
        if (cesarInt > 122) 
        {
            // Calculer le dépassement après 'z' et recommencer à 'a'
            cesarInt = (cesarInt - 123) + 97; // 123 est 'z' + 1, 97 est 'a'
        }
      	cesarChar = cesarInt; // Convertir la valeur encodée en int en char
		    message += readChar; // Ajouter le caractère au message
        messageCoder += cesarChar; // Ajouter le caractère codé au message codé
    }

    if (message.length() > 0) // Si un message a été reçu
    {
        Serial.println(); // Nouvelle ligne après le message
        Serial.println("Message complet : " + message); // Afficher le message complet
        Serial.println("Message coder complet : " + messageCoder); // Afficher le message codé complet
    }

    delay(100); // Petit délai pour éviter une surcharge du port série
}