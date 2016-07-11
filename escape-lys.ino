/*
 * This code fades through the BLUE and RED spectre of a RGB LED-strip
 * See: https://github.com/cybrairai/LED-Arduino/
 * 
 * The pin used for RED is 6 and 5 for BLUE, which is defined bellow
 * 
 * Author: Adrian Helle (adriah)
 */
#define RED 6
#define BLUE 5

//The current fade value
int valRed;
int valBlue;

//booleans to check if it should fade the color down or up
bool downR;
bool downB;

void setup() {
	pinMode(RED, OUTPUT);
	pinMode(BLUE, OUTPUT);
	valRed = 0;
	valBlue = 125;
	downR = false;
	downB = true;
}

void loop() {
	if (valRed == 100) {
		downR = true;
	} else if (valRed == 5){
		downR = false;
	}
	if (valBlue == 250) {
		downB = true;
	} else if (valBlue == 40) {
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

	delay(80);
}
