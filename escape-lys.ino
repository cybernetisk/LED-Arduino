/*
* This code fades through the BLUE and RED spectre of a RGB LED-strip
* See: https://github.com/cybrairai/LED-Arduino/
*
* Author: Adrian Helle (adriah)
*/
#define RED 6
#define GREEN 3
#define BLUE 5
#define BUTTON_MODE 2
#define BUTTON_MODE2 4
#define BUTTON_R 7
#define BUTTON_G 8
#define BUTTON_B 10
#define BUTTON_OFF_ON 9
//#define LATCH_PIN 11
//#define CLOCK_PIN 12
//#define DATA_PIN 13
#define POT_METER A0
// Uncomment this for serial debugging:
//#define DEBUG

//The current fade value
int valRed;
int valBlue;

//booleans to check if it should fade the color down or up
bool downR;
bool downB;

int mode = 0000;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(POT_METER, INPUT);
  pinMode(BUTTON_MODE, INPUT_PULLUP);
  pinMode(BUTTON_MODE2, INPUT_PULLUP);
  pinMode(BUTTON_R, INPUT_PULLUP);
  pinMode(BUTTON_G, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_OFF_ON, INPUT_PULLUP);
  valRed = 0;
  valBlue = 125;
  downR = false;
  downB = true;
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
}

void loop()
{
  if (digitalRead(BUTTON_MODE) == LOW) {
    mode = 1000;
    #ifdef DEBUG
    Serial.println("MODE");
    #endif
    delay(200);
  } else if (digitalRead(BUTTON_R) == LOW) {
    mode = 0100;
    #ifdef DEBUG
    Serial.println("R");
    #endif
    delay(200);
  } else if (digitalRead(BUTTON_G) == LOW) {
    mode = 0010;
    #ifdef DEBUG
    Serial.println("G");
    #endif
    delay(200);
  } else if (digitalRead(BUTTON_B) == LOW) {
    mode = 0001;
    #ifdef DEBUG
    Serial.println("B");
    #endif
    delay(200);
  } else if (digitalRead(BUTTON_OFF_ON) == LOW){
    mode = 0000;
    #ifdef DEBUG
    Serial.println("OFF");
    #endif

    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
    delay(200);
  }

  if (mode == 1000) {
    fader();
  } else if (mode == 0100) {
    analogWrite(RED, analogRead(POT_METER)*1023/255);
  } else if (mode == 0010) {
    analogWrite(GREEN, analogRead(POT_METER)*1023/255);
  } else if (mode == 0001) {
    analogWrite(BLUE, analogRead(POT_METER)*1023/255);
  }
  #ifdef DEBUG
  Serial.println(analogRead(POT_METER));
  #endif
}

void fader() {
  if (valRed == 250) {
    downR = true;
  } else if (valRed == 5){
    downR = false;
  }
  if (valBlue == 250) {
    downB = true;
  } else if (valBlue == 5) {
    downB = false;
  }

  if(downR) {
    valRed-=1;
  } else {
    valRed+=1;
  }
  if(downB) {
    valBlue-=1;
  } else {
    valBlue+=1;
  }

  analogWrite(RED, valRed);
  analogWrite(BLUE, valBlue);

  delay(60);
}
