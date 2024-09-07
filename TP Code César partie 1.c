# Titre : TP Code César partie 1.c
*06/09/2024*

##Code : 

```c++
//c++ code
//TP Code César partie 1.c

int key = 6; //variable globale de la clef

void setup()
{
    Serial.begin(9600);
    
}

void loop()
{
    char readChar = 0; // caractère à lire

    int buff = Serial.available();

    while(buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
      	int numchar = readChar;
		
      
      	//condition pour touts les caractère DEC + key > 122 
      	if(numchar + key > 122){
      		int numcharReset = 'a';
            int reset = (numchar + key) - 122;
          	//Serial.println(reset);
            char newcaratere = (numcharReset + reset)-1 ;
            Serial.print(newcaratere); // envoi du caractère
            buff = Serial.available(); // mise à jour du nombre de caratères restant
        }else{
        char newcaratere = numchar + key ;
        Serial.print(newcaratere); // envoi du caractère
        buff = Serial.available();
        }
        	
      
       
    }
}

//int variable = 'A';
//char caractere = variable + 1;
//Serial.println(caractere);
```
