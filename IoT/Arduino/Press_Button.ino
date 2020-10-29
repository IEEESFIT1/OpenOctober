const int buttonPin = 7;  
const int ledPin =  12;  

int buttonState = 0;  

void setup() 
{
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
}

void loop() 
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) 
  {
    digitalWrite(ledPin, LOW);
  } 
  else
  {
    digitalWrite(ledPin, HIGH);
  }
}

