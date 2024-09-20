```
void print(const char* format, ...)
{
  	char buffer[512];

  	va_list args;
  	va_start(args, format);
  	vsprintf(buffer, format, args);
  	va_end(args);

  	Serial.println(buffer);
}

void setup()
{
	Serial.begin(9600);
}

void loop()
{
  char cafe[] = "café";
  char chocolat[] = "chocolat chaud";
  char the[] = "thé";
  char boisson[50];
  
  int nbrcafe = 10, nbrchoc = 10, nbrthe = 10;
  
  if (Serial.available() > 0) 
  {
	int index = 0;
    while (Serial.available() > 0) 
    {
     	char c = Serial.read();
        if (c == '\n') break;
        boisson[index++] = c;
    }
    boisson[index] = '\0';
    
    
    if (strcasecmp(boisson, cafe) == 0) 
    {
    	if (nbrcafe > 0) 
        {
        	nbrcafe--;
            print("Vous avez commandé un %c.", cafe);
        } 
      	else 
        {
        	print("Désolé, il n'y a plus de café disponible.");
        }
   }
    
    
   	else if (strncmp(boisson, chocolat, strlen(chocolat)) == 0) 
    {
        if (nbrchoc > 0) 
        {
            nbrchoc--;
            print("Vous avez commandé un %c.", chocolat);
        } 
      	else 
        {
            print("Désolé, il n'y a plus de chocolat chaud disponible.");
        }
    } 
    
    
   	else if (strcasecmp(boisson, the) == 0) 
    {
        if (nbrthe > 0) 
        {
            nbrthe--;
            print("Vous avez commandé un %c.", the);
        } 
      	else 
        {
            print("Désolé, il n'y a plus de thé disponible.");
        }
    } 
    
    
   	else 
   	{
      	print("Commande invalide.");
   	}
  }
}
```
