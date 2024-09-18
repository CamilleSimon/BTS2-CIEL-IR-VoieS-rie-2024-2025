


void setup()
{
    Serial.begin(9600);

  
}

void loop()
{
  String mpr = "0,6,gdrgdrgd" ; // La taille du tableau chaine est automatiquement calculée
  
  int ope = mpr.substring(0,1).toInt();
  int key = mpr.indexOf(',',',');
  
  int rt = mpr.indexOf(',', 2);
  String mdp = mpr.substring(rt);
  
  if(ope = 0)
  {



    int buff = Serial.available();

    while(buff > 0 ) // tant qu'il reste des caractères dans le buffer
    {
        char cChiff = mdp - key ; 

      if( cChiff < 97)
      {
        char cChiff1 = cChiff + 26;
        Serial.print(cChiff1); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
        
      }
      else 
      {
        Serial.print(cChiff); // envoi du caractère
        buff = Serial.available(); // mise à jour du nombre de caratères restant
      }
    }

   
  
  else
  {
  
    int buff1 = Serial.available();

    while(buff1 > 0 ) // tant qu'il reste des caractères dans le buffer
    {
       
        char cChiff1 = mdp + key ; 

      if( cChiff1 > 122)
      {
        char cReste1 = cChiff1 - 122;
        char cChiff11 = 97 + cReste1;
        Serial.print(cChiff11); // envoi du caractère
        buff1 = Serial.available(); // mise à jour du nombre de caratères restant
        break ; 
      }
      else 
      {
        Serial.print(cChiff); // envoi du caractère
        buff1 = Serial.available(); // mise à jour du nombre de caratères restant
      }
    }
  }
  
  
  
  
  
  
  
  
 
  

  
}



