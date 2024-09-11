int key; // definir une variable
int operation; // definir 
int message;

void setup()// crée une fonction
{
    Serial.begin(9600);
}

void loop()// crée une fonction
{ 
    
   char readChar = 0; // caractère à lire
   int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
        tab[i] = readChar; //tab[i]=acceder à une case du tableau readchar=lire la
        i++;
    }
      
    if (operation = 0)
    {
      chiffrement;
     
    }
    else 
    {
       dechiffrement;
    }
      
    int tableau[256];
  
  tableau[0]= operation;
  tableau[1]= key;
  tableau[2]= message;
}
void chiffrement()// crée une fonction
{
    
  
  char readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        readChar = readChar +key; // caractère à lire
        Serial.print(readChar); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      if (readChar>122);
      {
       readChar = readChar -26; 
  

}
void dechiffrement()// crée une fonction
{
   char readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        readChar = readChar -key; // caractère à lire
        Serial.print(readChar); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      if (readchar>122);
      {
       readchar = readchar -26; 
}
