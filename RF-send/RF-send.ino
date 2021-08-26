#include <VirtualWire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
 
const int RF_TX_PIN = 2;

const int colorR = 255;
const int colorG = 0;
const int colorB = 255;
 
void setup()
{
  vw_set_tx_pin(RF_TX_PIN); // Setup transmit pin
  vw_setup(250); // Transmission speed in bits per second.
  pinMode(3, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}
 
void loop()
{
  int buttonstate = digitalRead(3);
  const char *msg = "LDBP";
  if (buttonstate == HIGH){
    vw_send((uint8_t *)msg, strlen(msg));
    lcd.clear();
    lcd.setCursor(0,0); //set cursor on first line first char
    lcd.setRGB(255,0,0);
    lcd.print("Sending: ");
    lcd.setCursor(0,1); //set cursor second line first char
    lcd.print(msg);
    delay(5000);
  } else {
    lcd.clear();
    lcd.setRGB(colorR, colorG, colorB);
    lcd.setCursor(0,0);
    lcd.print("Wting for press.");
    lcd.setCursor(0,1);
    lcd.print("Press 1 sec");
    delay(1000);
  }
 
}
