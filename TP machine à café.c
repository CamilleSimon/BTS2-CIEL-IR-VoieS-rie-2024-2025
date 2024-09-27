```C++
int pinsled[3]={13,12,11}; // Stockage des valeurs des pins des leds dans un tableau de 3 entiers (11=thé, 12= chocolat, 13=cafe)
int pinsbouton[3]={4,3,2}; // Stockage des valeurs des pins des boutons dans un tableau de 3 entiers (4=cafe, 3=chocolat, 2=the)
int stocks[3]={10,10,10}; // Stockage des valeurs des stocks des boissons dans un tableau de 3 entiers(10=cafe, 10=chocolat, 10=the)
String valide[3]={"cafe","chocolat","the"}; // Stockage des mots valides entré par l'utilisateur dans un tableau de 3 chaîne de caractères

void remplir(int type_boisson) // Fonction pour remplir le stock de boisson
{
  if(stocks[type_boisson] == 10) // Si le stock est déjà de 10 boisson dans la boisson correspondante
  {
    Serial.println("Le stock de " + valide[type_boisson] + " est deja plein"); // On envoie à l'utilisateur que le stock est déjà plein
  }
  if(stocks[type_boisson] < 10) // Si le stock est en dessous de 10 boissons dans la boisson correspondante
  {
    stocks[type_boisson] = 10; // Remettre le stock de la boisson en question à 10
    Serial.println("Le stock de " + valide[type_boisson] + " a ete renouvele"); // On affiche que le stock de la boisson a été renouvelé
  }
}
String receptionCommande() // Fonction pour la récéption de la commande
{
  String message = Serial.readStringUntil('\n'); // Lecture du message entré jusqu'au caractère de fin de ligne "\n"
  return message; // On retourne le message en question
}
void servirBoisson(int type_boisson)// Fonction lorsque la boisson doit être servi
{
  if(stocks[type_boisson] == 0) // On check s'il n'y a plus de boisson dans celle que l'utilisateur à choisie
  {
    Serial.println("Plus de stock de " + valide[type_boisson] + ". Veuillez appuyer sur le bouton correspondant pour remplir le stock"); // On demande a l'utilisateur d'appuyer sur le bouton
  }
  if(stocks[type_boisson] > 0) // Check s'il y a plus de 0 boisson dans le stock
  {
    stocks[type_boisson] = stocks[type_boisson] - 1; // On enlève 1 dans le stock de la boisson choisie
    Serial.println("Votre boisson est servie"); // On envoie que la boisson est bien servie
    Serial.println("Stocks restant : "); // On affiche le stock de boisson restante
    Serial.println(valide[type_boisson] + " : " + stocks[type_boisson]); // Boisson correspondante ainsi que son stock
  }

    
}
void checkLumiere(int type_boisson) // Fonction du check des leds
{
  if(stocks[type_boisson] <= 10 && stocks[type_boisson] > 5) // S'il y a entre 10 inclus et 5 non inclus de boisson dans le stock
  {
    digitalWrite(pinsled[type_boisson], HIGH); // La led correspondante à la boisson reste éteinte
  }
  else if(stocks[type_boisson] <= 5 && stocks[type_boisson] > 3) // S'il y a entre 5 inclus et 3 non inclus de boisson dans le stock
  {
    for (int i = 0; i < 5; i++) // Petite boucle qui se repete 5 fois pour faire clignoter la led correspondante 
    {
      digitalWrite(pinsled[type_boisson], LOW);  // On allume la led correspondante à la boisson
      delay(500);								 // On attend 0.5 seconde
      digitalWrite(pinsled[type_boisson], HIGH); // On eteint la led correspondante à la boisson
      delay(500);								 // On attend 0.5 seconde
    }
  }
  else if(stocks[type_boisson] <= 3) // S'il y a moins de 3 boisson dans le stock avec 3 inclus
  {
    digitalWrite(pinsled[type_boisson], LOW); // On allume la led correspondante à la boisson
  }
}


void setup()
{
  Serial.begin(9600); // Initialisation de la vitesse de transmission à 9600 bauds
  
  // Initialisation des 3 leds en mode OUTPUT et des 3 boutons en mode INPUT
  pinMode(pinsled[2], OUTPUT);
  pinMode(pinsled[1], OUTPUT);
  pinMode(pinsled[0], OUTPUT);
  pinMode(pinsbouton[2], INPUT);
  pinMode(pinsbouton[1], INPUT);
  pinMode(pinsbouton[0], INPUT);
  
  // Initialisation des 3 leds et des 3 boutons à l'état HIGH
  digitalWrite(pinsled[2], HIGH);
  digitalWrite(pinsled[1], HIGH);
  digitalWrite(pinsled[0], HIGH);
  digitalWrite(pinsbouton[2], HIGH);
  digitalWrite(pinsbouton[1], HIGH);
  digitalWrite(pinsbouton[0], HIGH);
}

void loop()
{
  for (int i = 0; i < 3; i++) // Boucle for des boutons (0,1,2) pour chaque boutons 
  {
    if (digitalRead(pinsbouton[i]) == LOW) // Si un des 3 boutons est appuyé
    {
      remplir(i); // On appelle la fonction pour remplir le stock de la boisson dont on veut remplir le stock
      checkLumiere(i); // On check la lumière du stock pour qu'elle repasse à 10 donc led éteinte
      delay(1000); // Ajout d'un délai de 1 seconde pour ne pas recevoir trop de message de la fonction remplir()
    }
  }
  
  
  while(Serial.available() > 0)
  {
    String message = receptionCommande(); // On donne a la variable message le résultat de la receptionCommande() (le message de l'utilisateur)
    if(message != valide[0] && message != valide[1] && message != valide[2]) // Condition pour savoir si le message entré est valide ou non
    {
      Serial.println("Mauvais choix, les choix sont : cafe, chocolat, the"); // Si jamais le message entré ne correspond pas à la liste des mots valides, on envoie un message d'erreur à l'utilisateur
    }
    while(message == valide[0] || message == valide[1] || message == valide[2]) // Boucle while qui vérifie si le message est égal a valide[0](cafe) ou valide[1](chocolat) ou valide[2](the)
    {
      if(message == valide[0]) // Condition pour le café
      {
        Serial.println("Preparation de votre " + message); // On envoie que la préparation de la boisson est en cours
        servirBoisson(0); // Appel de la fonction servirBoisson qui va enlever 1 au stock de café
        checkLumiere(0); // Appel de la fonction checkLumiere qui va actualiser l'état de la led du café
        message = receptionCommande(); // On remet a la variable message le resultat de la fonction receptionCommande(). A ce moment là la variable ne contient plus rien
      }
      else if(message == valide[1]) // Condition pour le chocolat
      {
        Serial.println("Preparation de votre " + message); // On envoie que la préparation de la boisson est en cours
        servirBoisson(1); // Appel de la fonction servirBoisson qui va enlever 1 au stock de chocolat chaud
        checkLumiere(1); // Appel de la fonction checkLumiere qui va actualiser l'état de la led du chocolat chaud
        message = receptionCommande(); // On remet a la variable message le resultat de la fonction receptionCommande(). A ce moment là la variable ne contient plus rien
      }
      else if(message == valide[2]) // Condition pour le thé
      {
        Serial.println("Preparation de votre " + message); // On envoie que la préparation de la boisson est en cours
        servirBoisson(2); // Appel de la fonction servirBoisson qui va enlever 1 au stock de thé
        checkLumiere(2); // Appel de la fonction checkLumiere qui va actualiser l'état de la led du thé
        message = receptionCommande(); // On remet a la variable message le resultat de la fonction receptionCommande(). A ce moment là la variable ne contient plus rien
      }
    }
  }  
}
```
