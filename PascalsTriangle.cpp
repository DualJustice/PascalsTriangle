#include "Arduino.h"
#include "HardwareSerial.h"


int inputLoop() {
	String userInput;

	while(true) {
		if(Serial.available() > 0) {
			userInput = Serial.readStringUntil('\n');
			Serial.print("You input: ");
			Serial.println(userInput);
			break;
		}

		else {
			delay(100);
		}
	}

	return userInput.toInt();
}


int *buildTri(int inRow) {
	int *currentRow = new int[inRow];
	for(int i = 0; i < inRow; i += 1) {
		currentRow[i] = 0;
	}

	int n = 0;

	while(n < inRow) {
		currentRow[0] = 1;

		for(int k = 0; k < n; k += 1) {
			currentRow[k + 1] = (currentRow[k]*(n - k))/(k + 1);
		}

		for(int i = 0; i <  ((inRow - 1) - n); i += 1) {
			Serial.print(" ");
		}

		for(int i = 0; i < inRow; i += 1) {
			if(currentRow[i] != 0) {
				Serial.print(currentRow[i]);
				Serial.print(" ");
			} else {
				break;
			}
		}

		Serial.println();
		n += 1;
	}

	delete[] currentRow;
}


void askRow() {
	Serial.println("Input the number of rows you'd like to calculate.");

	int inRow = 0;

	while(true) {
		inRow = inputLoop();

		if(inRow < 1) {
			Serial.println("Make sure you input a valid row number.");
		}

		else {
			buildTri(inRow);
			break;
		}
	}
}


void setup() {
	Serial.begin(9600);
	while(!Serial) {
		delay(250);
	}
}


void loop() {
	askRow();
}