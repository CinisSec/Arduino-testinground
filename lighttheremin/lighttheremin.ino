int sensorvalue;
int sensorlow = 1023;
int sensorhigh = 0;

const int ledpin = 13;

void setup() {
  pinMode(ledpin, OUTPUT);
  digitalWrite(9, HIGH);
 while(millis() < 5000){
  sensorvalue = analogRead(A0);
  if(sensorvalue > sensorhigh){
    sensorhigh = sensorvalue;
  }
 }
 digitalWrite(ledpin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorvalue = analogRead(A0);
int pitch = map(sensorvalue, sensorlow, sensorhigh, 50, 4000);
tone(8,pitch,20);
delay(10);
}
