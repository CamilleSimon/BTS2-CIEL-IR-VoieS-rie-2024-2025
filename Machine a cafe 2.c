const int COUNT = 3; 
const int PINLEDS[COUNT] = {13, 12, 11};
const int PINBUTTON[COUNT] = {4, 3, 2};
int stockBoisson[COUNT] = {10,4,1};
const String NOMBOISSON[3] =  {"cafe", "chocloat", "the"};

void setup ()
{
    for(int i = 0; i < COUNT; i++) {
        pinMode(PINLEDS[i], OUTPUT);
        pinMode(PINBUTTON[i], INPUT);
      	digitalWrite(PINLEDS[i], HIGH);
      	digitalWrite(PINBUTTON[i], HIGH);

    }
  Serial.begin(9600);
}

void loop ()
{
  
}
void remplir(int type_boisson) {
  
}
