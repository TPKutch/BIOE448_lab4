const int trigPin = 11;
const int echoPin = 12;
const int LedPin1 = 3;
const int LedPin2 = 4;
long duration;
int distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LedPin1, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distanceCm = duration * 1/58;
  distanceInch = duration * 1/148;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  delay(1000);
  
  if (distanceCm < 5) {
    digitalWrite(LedPin1, HIGH);
    digitalWrite(LedPin2, LOW); }
    
    else{
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin2, HIGH);
    }
}
