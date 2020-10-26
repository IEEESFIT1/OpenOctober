// Code by Kartikey Sharma
// Contributed to OpenOctober
const int ledPin =  LED_BUILTIN;
int ledState = HIGH;
unsigned long previousMillis = 0; 
const long interval = 1000;     
// Setting up the pin to OUTPUT mode
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  unsigned long currentMillis = millis();
  if (interval <= currentMillis - previousMillis) {
    previousMillis = currentMillis;
    if (ledState == HIGH) {
      ledState = LOW;
    } 
	else {
      ledState = HIGH;
    }
    digitalWrite(ledPin, ledState);
  }
}

