#include <LiquidCrystal.h>
#include <TMP36.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

TMP36 tempsensor(A0, 5.0);
int tempchange = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  float temp = tempsensor.getTempC();
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  if(temp > tempchange + 0.5 or temp < tempchange - 0.5){
      tempchange = temp;      
      lcd.setCursor(0, 1);
      lcd.print(temp, 1);
      delay(1000);
      }
  lcd.setCursor(12,1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
