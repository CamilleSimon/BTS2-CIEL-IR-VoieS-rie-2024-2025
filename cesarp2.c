int key = 6;
int operation;
void setup() {

    Serial.begin(9600);
    Serial.println("");
    key = 6;
    String message = "0,6,bonjour";
    //Serial.print(message.substring(0,6));
    operation = message.substring(0, 6).toInt();
    Serial.println(message.substring(0, 6));

    //operaion = message.substring(0,6);


      //int index = message.indexOf();
     //Serial.println(index);
     //String message = "bonjour";
    String messageChiffre = chiffrement(message); //->"hutupax";
    String messageDechiffre = dechiffrement(message); //->"hutupax";

}



String chiffrement(String message)
{
    String messageChiffre;
    for (int i = 0; i < message.length(); i++)
    {
        char readChar = message[i] + key;
        messageChiffre += readChar;

    }
    return messageChiffre;
}


String dechiffrement(String message)
{
    String messageDechifrement;
    for (int i = 0; i < message.length(); i++)
    {
        char readChar = message[i] - key;
        messageDechifrement += readChar;

    }
}

void loop()
{
    int buff = Serial.available();
    char readChar;
    String s = "";

    while (buff > 0) // tant qu'il reste des caractères dans le buffer
    {
        readChar = Serial.read(); // lecture du caractère
        s = readChar;
        buff = Serial.available(); // mise à jour du nombre de caratères restant
        Serial.print(s);
    }
}


