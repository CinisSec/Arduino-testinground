#include <Servo.h>

Servo myservo;

int const potPin=A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potVal = analogRead(potPin);
Serial.print("potVal: ");
Serial.print(potVal);
angle = map(potVal, 0, 1023, 0, 179);
Serial.print("Angle: ");
Serial.print(angle);
myservo.write(angle);
delay(15);
}
