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
  vw_setup(2000); // Transmission speed in bits per second.
  pinMode(6, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}
 
void loop()
{
  int buttonstate = digitalRead(6);
  const char *msg = "LDBP";
  if (buttonstate == HIGH){
    vw_send((uint8_t *)msg, strlen(msg));
  }
 
}
