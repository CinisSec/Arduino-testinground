int sensorinput;
double temp;

void setup() {
Serial.begin(9600);
}
void loop() {
  sensorinput = analogRead(A0);
  temp = (double)sensorinput / 1024;
  temp = temp * 5;
  temp = temp - 0.5;
  temp = temp * 100;
  if ((int)temp > 20){
    digitalWrite(4, HIGH);
    }else {digitalWrite(4, LOW);}
    if ((int)temp > 25){
      digitalWrite(3, HIGH);
      } else {digitalWrite(3, LOW);}
    if ((int)temp >= 30){
      digitalWrite(2, HIGH);
    } else {digitalWrite(2, LOW);}
  Serial.print("Temperature: ");
  Serial.print(temp);
  delay(500);
}
