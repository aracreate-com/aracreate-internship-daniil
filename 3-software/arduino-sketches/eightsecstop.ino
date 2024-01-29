void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (millis() / 1000 >= 8) {
    Serial.println("Time is out!");
    digitalWrite(LED_BUILTIN, LOW);
    for (;;);
  }
  digitalWrite(LED_BUILTIN, LOW);
  delay(3000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
