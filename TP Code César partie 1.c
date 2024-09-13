```C++
int key = 6; // Affectation de key à 6 pour décalage de 6

void setup()
{
    Serial.begin(9600);
}

void loop()
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
}
```
