int key = 6;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int num;
  int buffer = Serial.available();
  char car = 0;
  while(buffer > 0)
  {
  	num = Serial.read()+ key;
  	if(num > 122)
    	num -= 26;
    car = num;
  	Serial.print(car);
    buffer = Serial.available();
  }
}