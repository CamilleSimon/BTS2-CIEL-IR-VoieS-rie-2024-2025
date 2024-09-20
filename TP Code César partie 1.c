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
  String text ="";
  
  	char readChar = 0; // caractère à lire
    int buff = Serial.available();
    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        text = text+readChar;// ajouter le contenu de readChar dans text
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      	//Serial.print(readChar);
    }
    
    for(int i = 0;i<=text.length();i++)
    {
      if (text[i]>='u')
        text[i] =text[i]-26;
      text[i] = text[i] + key;
    }
    Serial.print(text);
}
