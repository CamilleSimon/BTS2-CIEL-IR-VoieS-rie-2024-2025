# Les liaisons séries - TP - Niveaux de la machine à café

## Conseils

-   Munissez vous d'une feuille de papier et d'un crayon pour comprendre comment ce TP fonctionne avant de vous lancez dans le code.
-   Lisez le TP en entier avant de commencer.
-   Commentez votre code et utilisez des noms de variables ayant du sens !
-   Utilisez Tinkercad pour tester votre code. Une fois que tout fonctionne, copier/coller votre code dans un fichier `TP machine à café.c`

## Enoncé

Vous êtes chargé de créer un système IoT pour le futur distributeur de café des étudiants. Ce distributeur peut délivrer trois boissons différentes. Pour commander leur boisson, les étudiants doivent taper le nom de celle-ci sur l'interface textuelle du distributeur. Le distributeur affiche en temps réel la quantité restante de chaque boisson dans la réserve de la machine à l'aide de LEDs de couleur.

Chaque LED correspond à une boisson :

-   Rouge : café
-   Jaune : chocolat chaud
-   Vert : thé

L'état de la LED indique le niveau de la réserve :

-   Éteinte : il reste plus de 50% dans la réserve.
-   Glignotante : il reste entre 50% et 25% dans la réserve.
-   Allumée : il reste moins de 25% dans la réserve.

Lorsque la réserve est pleine, elle contient de quoi préparer 10 boissons de chaque. La machine possède également trois boutons, un pour chaque boisson. Lorsqu'une réserve est remplie, on appuie sur le bouton correspondant pour indiquer qu'elle' est de nouveau pleine.

## Exercice

1. Sur Tinkercad, réalisez le montage représentant la machine à café.
Pour initialiser les leds et les boutons, vous pouvez utiliser les fonctions suivantes :
```ino
// pour les boutons
pinMode(2, INPUT); // initialise le pin numéro 2 comme étant un input
digitalWrite(2, HIGH); // met le pin 2 en état haut
// pour les leds
pinMode(13, OUTPUT); // initialise le pin numéro 13 comme étant un output
digitalWrite(13, HIGH); // met le pin 13 en état haut
```
2. Vous utiliserez des tableaux pour stocker les informations suivantes :
    * les pins des LEDs,
    * les pins des boutons,
    * les stocks des boissons,
    * le dictionnaire des commandes valides
3. Ecrivez les fonctions suivantes :
    1. `remplir(int type_boisson)` qui affecte `10` au stock de `type_boisson`.
    2. `receptionCommande()` qui récupère le contenu du buffer et compare avec les commandes possible.
    3. `servirBoisson(int type_boisson)` qui décompte le stock si cela est possible.
    4. `checkLumiere(int type_boisson)` qui met à jour l'état de la led de la boisson passée en paramètre.
4. Ecrivez les fonctions `setup()` et `loop()` en vous appuyant en utilisant les fonctions ci-dessus.

## Indications

-   Vous devrez utiliser des chaînes de caractères, (String). Vous trouverez [ici](https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/) la documentation de la classe String pour Arduino.
-   Pour faciliter la lecture de votre code, n'hésitez pas à le découper en fonctions.
-   Pour debugger votre code et afficher des messages complexes sur le moniteur de série, vous pouvez utiliser cette fonction :

```C
void print(const char* format, ...)
{
  char buffer[512];

  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);

  Serial.println(buffer);
}
```

La signature de la fonction `void print(const char* format, ...);` doit être placée avant la fonction `setup()`. Elle s'utilise de façon similaire à [printf](https://www.geeksforgeeks.org/printf-in-c/) :

```C
print("Mon message contenant un entier %d et une chaîne de caratère %s", var_entiere, var_string.c_str())
```
