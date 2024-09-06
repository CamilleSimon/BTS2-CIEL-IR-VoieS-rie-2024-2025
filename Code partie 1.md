```C++
int key = 6;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int caractere = 0; // caractère 
    int buff = 0;

    buff = Serial.available();

    while(buff > 0) 
    {
        caractere = Serial.read(); // lecture du caractère
      	caractere = caractere + key; // ajout de la cle au caractère
        if(caractere>122)
          caractere= caractere - 24;
      	char test = caractere;
      	Serial.print(test); // ecris le caractere
        buff = Serial.available(); //remet la valeur de depart
    }
}
```
