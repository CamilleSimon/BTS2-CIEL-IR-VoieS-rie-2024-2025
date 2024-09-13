void setup() {
  
  int key = 6;
  
  Serial.begin(9600);

}
  void loop()
  {
    if (Serial.available() > 0) {
    char inputChar = Serial.read();
      
    while(buff > 0) {

      if (inputChar >= 'a' && inputChar <= 'z') {
        char encryptedChar = (inputChar - 'a' + key) % 26 + 'a';
        Serial.print(encryptedChar);
      }
  }
