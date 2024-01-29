void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  if (Serial.available() > 0) {
    
    String inputString = Serial.readString();
    inputString.toLowerCase();
    
    if (inputString == "turn on") {

      Serial.println(inputString + "\non");
      digitalWrite(LED_BUILTIN, HIGH);
      
    } else if (inputString == "turn off") {

      Serial.println(inputString + "\noff");
      digitalWrite(LED_BUILTIN, LOW);
      
    } else {

      Serial.println(inputString + "\nnot detected");
      digitalWrite(LED_BUILTIN, LOW);
      delay(3000);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(3000);
      
    }
  }
}
