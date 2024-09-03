// C++ code
//
using namespace std;
void setup()
{
  // ouverture de la liaison à une vitesse de 9600 bits par seconde.
  	Serial.begin(9600);

}

void loop()
{	
    char readChar = 0; // caractère à lire
    int buff = 0;

    buff = Serial.available();
  	String message = "";

    while (buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        Serial.println(readChar); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      	message = message + readChar;
           Serial.println(message);
   }
}