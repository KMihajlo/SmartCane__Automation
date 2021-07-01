#define trigPin 13
#define echoPin 12
#define motor 7
#define buzzer 6

void setup()
{ 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer,OUTPUT);
}
void loop()
{ 
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.4;

  if (distance < 100) // Checking the distance
  { 
    digitalWrite(motor,HIGH); // When the distance below 100cm
    digitalWrite(buzzer,HIGH);
  } else
  {
    digitalWrite(motor,LOW);// when greater than 100cm
    digitalWrite(buzzer,LOW); 
  } 
  delay(500);
}
