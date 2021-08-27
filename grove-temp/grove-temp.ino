#include <math.h>
#include "rgb_lcd.h"

#define ROTARY_ANGLE_SENSOR A1
#define ADC_REF 5
#define GROVE_VCC 5
#define FULL_ANGLE 300

rgb_lcd lcd;

int backlight = 10;

int tempchange = 0;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

void setup()
{
    lcd.begin(16, 2);
    lcd.setRGB(backlight, backlight, backlight);
    pinMode(ROTARY_ANGLE_SENSOR, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int a = analogRead(pinTempSensor);
    
    float R = 1023.0/a-1.0;
    R = R0*R;
    float temp = 1.0/(log(R/R0)/B+1/298.15)-273.15;
    temp = temp - 1.35;

    float voltage;
    int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
    voltage = (float)sensor_value*ADC_REF/1023;
    float degrees = (voltage*FULL_ANGLE)/GROVE_VCC;

    backlight = map(degrees, 0, FULL_ANGLE, 0, 255);
    lcd.setRGB(backlight,backlight,backlight);
      if(temp > tempchange + 0.5 or temp < tempchange - 0.5){
      tempchange = temp;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperature:");
      lcd.setCursor(0, 1);
      lcd.print(temp, 1);
      delay(100);
      }
    
}
