int cafe;
int chocolat;
int the;
const int COUNT = 3;
String dico[] = { "cafe","chocolat","the" };
const int leds[COUNT] = { 13,12,11 };
const int pins_bouton[] = { 4,3,2 };
int stocks_boissons[] = { 10,10,10 };

void setup()
{
    Serial.begin(9600);
    // pour les boutons
    pinMode(4, INPUT);
    digitalWrite(4, HIGH);
    pinMode(3, INPUT);
    digitalWrite(3, HIGH);
    pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
    digitalWrite(2, HIGH); // met le pin 2 en état haut

    pinMode(11, OUTPUT);
    digitalWrite(11, HIGH);
    pinMode(12, OUTPUT);
    digitalWrite(12, HIGH);
    pinMode(13, OUTPUT); // initialise le pin numéro 13 comme étant un output
    digitalWrite(13, HIGH); // met le pin 13 en état haut

}


String receptiConommande(String mot)
{
    for (int m = 0; m <= 2; m++)
    {
        if (mot == dico[m])
        {
            servirBoisson(m);
        }

    }
}


void remplir(int type_boisson)
{
    stocks_boissons[type_boisson] = 10;
}

void servirBoisson(int type_boisson)
{
    Serial.println(type_boisson);
    stocks_boissons[type_boisson] -= 1;
    Serial.print("Commande de ");
    Serial.print(dico[type_boisson]);
    Serial.print(". Il reste ");
    Serial.println(stocks_boissons[type_boisson]);


}
void loop()
{
    for (int i = 0; i < 3; i++)
    {
        if (digitalRead(pins_bouton[i]) == LOW)
            remplir(i);
    }
    String mot = "";
    int buff = Serial.available();


    while (buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        char readChar = Serial.read(); // lecture du caractère
        mot += readChar;
        delay(2);
        buff = Serial.available();
    }
    if (mot != "")
        receptiConommande(mot);
    checkLumiere(0);
    checkLumiere(1);
    checkLumiere(2);

}





void checkLumiere(int type_boisson)
{
    if (stocks_boissons[type_boisson] > 5)
        digitalWrite(type_boisson, HIGH);

    if (stocks_boissons[type_boisson] < 5 && stocks_boissons[type_boisson] >2)
        delay(20);
    digitalWrite(type_boisson, LOW);
    delay(20);
    digitalWrite(type_boisson, HIGH);

    if (stocks_boissons[type_boisson] < 2)
        digitalWrite(type_boisson, LOW);
}
