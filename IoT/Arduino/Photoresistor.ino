const int sensorPin = 2;
const int ledPin = 7;
int lightCal;
int lightVal;

void setup()
{
  pinMode(ledPin, OUTPUT);
  lightCal = analogRead(sensorPin);
}

void loop()
{
  lightVal = analogRead(sensorPin);
  if (lightVal >= lightCal - 50)
  {
    digitalWrite(ledPin, LOW);
  }
  else
  {
    digitalWrite(ledPin, HIGH);
  }
}
