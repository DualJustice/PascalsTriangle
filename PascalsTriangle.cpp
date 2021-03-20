#include "Arduino.h"
#include "HardwareSerial.h"


int inputLoop() {
	int userInput = 0;

	while(true) {
		if(Serial.available() > 0) {
			userInput = Serial.parseInt();
			Serial.print("You input: ");
			Serial.println(userInput);
			break;
		}

		else {
			delay(100);
		}
	}

	return userInput;
}


int *buildTri(int row) {
	int *currentRow = new int[row];
	currentRow[0] = 1;

	for(int i = 1; i < row; i += 1) {
		currentRow[i] = currentRow[i - 1]*((row - i)/i);
	}

	for(int i = 0; i < row; i += 1) {
		Serial.print(currentRow[i]);
		Serial.print(" ");
	}

	Serial.println();
}


void askRow() {
	Serial.println("Input the row you would like to calculate to.");

	while(true) {
		int row = inputLoop();

		if(row < 1) {
			Serial.println("Make sure you input a valid row number.");
		}

		else {
			buildTri(row);
			break;
		}
	}
}


void setup() {
	Serial.begin(9600);
	while(!Serial) {
		delay(250);
	}

	askRow();
}


void loop() {

}