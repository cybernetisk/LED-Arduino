int red = 6;
int blue = 5;

int valRed;
int valBlue;
bool downR;
bool downB;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  valRed = 0;
  valBlue = 125;
  downR = false;
  downB = true;
}

void loop() {
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

  analogWrite(red, valRed);
  analogWrite(blue, valBlue);
  
  delay(60);
}
