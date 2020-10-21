//This program is a simple Arduino program that causes an external LED to blink
//Contributed by Puranjay N Potnis
int LEDPin = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  // put your code that runs repeatedly here:
  digitalWrite(LEDPin, HIGH);
  delay(500);// Delay a little bit to improve simulation performance
  digitalWrite(LEDPin, LOW);
  delay(500);
}
