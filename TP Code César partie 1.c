// C++ code
//
int key = 6;
void setup()
{
    // ouverture de la liaison à une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
}
void loop()
{

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {	
      	char buff2 = Serial.read(); // caractère à lire
      	
  		buff2 = buff2 + key;
      
      if (buff2 > 122){
        	buff2 = buff2 - 26;
      }
        Serial.print(buff2); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
    }
}
