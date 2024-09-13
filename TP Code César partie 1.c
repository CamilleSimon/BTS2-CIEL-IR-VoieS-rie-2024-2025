// C++ code
//

int key = 6;  // Clé de chiffrement 

void setup()
{
    Serial.begin(9600);
}


void loop()
   
{
 char readChar = 0;  // Caractère à lire
    int buff = Serial.available();  // Nombre de caractères disponibles dans le buffer

    while (buff > 0) {  // Tant qu'il y a des caractères dans le buffer
        readChar = Serial.read();  // Lire un caractère du buffer

        
        if (readChar >= 'a' && readChar <= 'z') { // Vérifie si le caractère est une lettre minuscule
            readChar += key;  // Appliquer le décalage

            
            while (readChar > 'z') { // Ajuste le caractère si le décalage dépasse 'z'
                readChar -= 26;  // Revenir au début de l'alphabet
            }
        }

        Serial.print(readChar);  // Affiche le caractère chiffré ou non
        buff = Serial.available();  // Met à jour le nombre de caractères restants
    }
}
