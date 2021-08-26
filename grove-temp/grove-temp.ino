#include <math.h>
#include "rgb_lcd.h"

#define ROTARY_ANGLE_SENSOR A1

#define ADC_REF 5   //reference voltage of ADC is 5v.If the Vcc switch on the seeeduino
                    //board switches to 3V3, the ADC_REF should be 3.3
#define GROVE_VCC 5 //VCC of the grove interface is normally 5v

#define FULL_ANGLE 300 //full value of the rotary angle is 300 degrees

rgb_lcd lcd;

int colorR = 10;
int colorG = 10;
int colorB = 10;

int tempchange = 0;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

void setup()
{
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    pinMode(ROTARY_ANGLE_SENSOR, INPUT);
    Serial.begin(9600);
}

void loop()
{
    
    int a = analogRead(pinTempSensor);
    if(a != tempchange) 
    {
      tempchange = a;
      float R = 1023.0/a-1.0;
      R = R0*R;
      float temp = 1.0/(log(R/R0)/B+1/298.15)-273.15;
      temp = temp - 1.35;
      Serial.println(temp);
      lcd.setCursor(0, 0);
      lcd.print("Temperature:");
      lcd.setCursor(0, 1);
      lcd.print(temp, 1);
      delay(5000);
    }
    



    
    
    
}
