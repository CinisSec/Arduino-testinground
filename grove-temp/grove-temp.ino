#include <math.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 255;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0

void setup()
{
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    Serial.begin(9600);
}

void loop()
{
    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;
 
    float temp = 1.0/(log(R/R0)/B+1/298.15)-273.15;
    temp = temp - 1.35;
    Serial.println(temp);
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor(0, 1);
    lcd.print(temp, 1);
    delay(1000);
    
}
