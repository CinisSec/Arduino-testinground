#include <math.h>
#include "rgb_lcd.h"

#define POTMETER A1
#define ADC_REF 5
#define GROVE_VCC 5
#define FULL_ANGLE 300

rgb_lcd lcd;
const int btnpin1 = 4;
int backlight = 10;

int tempchange = 0;
int mode = 0;
int state = 0;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

void setup()
{
    lcd.begin(16, 2);
    lcd.setRGB(backlight, backlight, backlight);
    pinMode(POTMETER, INPUT);
    pinMode(btnpin1, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int a = analogRead(pinTempSensor);
    
    float R = 1023.0/a-1.0;
    R = R0*R;
    float temp = 1.0/(log(R/R0)/B+1/298.15)-273.15;
    temp = temp - 1.35;

    bool btn1 = digitalRead(btnpin1);

    float voltage;
    int sensor_value = analogRead(POTMETER);
    voltage = (float)sensor_value*ADC_REF/1023;
    float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;

    backlight = map(degrees, 0, FULL_ANGLE, 0, 255);

    tempcolor(temp,backlight);

    //changemode
    if(mode == 0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Hey there! Press");
      lcd.setCursor(0,1);
      lcd.print("to change mode.");
      delay(100);
      if(btn1 == HIGH){
      mode = 1;
      }
    }
    if(mode == 1){
      tempchange = temp;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperature: ");
      lcd.print(temp, 0);
      delay(100);
      state = state + 1;
      if (state > 2){
        state = 2;
      }
      if(state >= 2 and btn1 == HIGH ){
        mode = 0;
        state = 0;
      }
      }
}

void tempcolor(float temp,int backlight){
  if(temp > 25){
      lcd.setRGB(backlight,0,0);
    }else if(temp <= 18){
      lcd.setRGB(0,0,backlight);
    }else{
      lcd.setRGB(0,backlight,0);
    }
}
