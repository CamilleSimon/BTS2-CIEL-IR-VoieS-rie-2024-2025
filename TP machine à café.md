# Les liaisons séries - TP - Niveaux de la machine à café

## Enoncé

Vous êtes chargé de créer un système IoT pour le futur distributeur de café des étudiants. Ce distributeur peut délivrer trois boissons différentes. Pour commander leur boisson, les étudiants doivent taper le nom de celle-ci sur l'interface textuelle du distributeur. Le distributeur affiche en temps réel la quantité restante de chaque boisson dans la réserve de la machine à l'aide de LEDs de couleur.

Chaque LED correspond à une boisson :

-   Rouge : café
-   Jaune : chocolat chaud
-   Vert : thé

L'état de la LED indique le niveau de la réserve :

-   Éteinte : il reste plus de 75% dans la réserve.
-   Allumée : il reste moins de 25% dans la réserve.

Lorsque la réserve est pleine, elle contient de quoi préparer 10 boissons de chaque. La machine possède également trois boutons, un pour chaque boisson. Lorsqu'une réserve est remplie, on appuie sur le bouton correspondant pour indiquer qu'elle' est de nouveau pleine.

## Exercice

1. Sur Tinkercad, réalisez le montage représentant la machine à café.
2. Ecrivez le code permettant de :
    1. Commander une boisson.
    2. Allumer les LEDs en fonction du niveau de la réserve de chaque boisson.
    3. Réinitialisez l'état de la réserve lorsque l'on appuie sur le bouton correspondant.

## Indications

-   Vous devrez utiliser des chaînes de caractères, (String). Vous trouverez [ici](https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/) la documentation de la classe String pour Arduino.
-   Pour faciliter la lecture de votre code, n'hésitez pas à le découper en fonctions.
