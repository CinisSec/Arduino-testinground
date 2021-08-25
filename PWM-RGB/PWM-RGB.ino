const int redrgbpin = 11;
const int bluergbpin = 10;
const int greenrgbpin = 9;

const int redsensorpin = A0;
const int bluesensorpin = A1;
const int greensensorpin = A2;

int red = 0;
int blue = 0;
int green = 0;

int redsensor = 0;
int bluesensor = 0;
int greensensor = 0;



void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(redrgbpin, OUTPUT);
 pinMode(bluergbpin, OUTPUT);
 pinMode(greenrgbpin, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  redsensor = analogRead(redsensorpin);
  delay(5);
  bluesensor = analogRead(bluesensorpin);
  delay(5);
  greensensor = analogRead(greensensorpin);
  
  red = random(255);
  blue = random(255);
  green = random(255);
  
  analogWrite(redrgbpin,red);
  delay(100);
  analogWrite(bluergbpin,blue);
  delay(200);
  analogWrite(greenrgbpin,green);
  delay(100);
  
}
