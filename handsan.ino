#define echoPin 2
#define trigPin 3
#include <Servo.h>

long duration;
int distance;

const int servoPin1 = 6;
const int servoPin2 = 7;

Servo servoMotor1;
Servo servoMotor2;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servoMotor1.attach(servoPin1);
  servoMotor2.attach(servoPin2);
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Serial.print("duration: ");
  Serial.print(duration);

  distance = ((duration/2)/29);
  Serial.print("Distance: ");
  Serial.print(distance);
  if(distance<=30)
  {
    servoMotor1.write(90);
    servoMotor2.write(90);
    delay(50);
  }
  else
  {
    servoMotor1.write(0);
    servoMotor2.write(0);
    delay(50);
  }
  delay(50);
}
