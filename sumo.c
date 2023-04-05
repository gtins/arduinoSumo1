int sensorCor0 = A0;
int sensorCor1 = A1;
int motor1 = 2;
int motor2 = 7;
void setup(){
    Serial.begin(9600);
}
void loop(){
  Serial.println(analogRead(A1));
  delay(100);
  Serial.println(analogRead(A1));
  delay(100);
  if (analogRead(A0) < 700){
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
}