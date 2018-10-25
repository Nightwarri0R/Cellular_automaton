#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "1dca.h"

int main(void) {
	int *rule;
	int row[80];
	int rowSize = 80;

	for (int i=0; i<rowSize; i++)
		row[i] = 0;

	row[40] = 1;

	//int rule[] = {0,1,1,1,1,0,0,0};
	//            1 2 4 8 16 32 64 128

	

	int input;
	printf("Rule: ");
	scanf("%d", &input);
	rule = decimalToBinary(input);
	printRow(row, rowSize);
	printf("\n");
	//rule = decimalToBinary(rnd());

	for (int i=0; i<100; i++) {
		calculateNextRow(row, rule, rowSize);
		printRow(row, rowSize);
		printf("\n");
	}

	/*
	CHECK
	*/
	printf("\n_____________________________________");
	printf("                                        ");
	printf("\nRule: %d", binaryToDecimal(rule));
	printf("\n");
	printf("2^n:     1  2  4  8 16 32 64 128");
	printf("\n");
	printf("Binary: ");
	for (int i = 0; i < 8; i++) {
		printf(" %d ", *(rule + i));
	}
	printf("\n_____________________________________");
	printf("\n");
	
	/*
	*/
}

void printRow(int row[], int rowSize) {
	// prints a white block if the arr contains 1. blank for 0
	for (int i=0; i<rowSize; i++)
		if (row[i] == 1)
			printf("\u2588");
		else
			printf(" ");
}

int calculateCell(int lastRowLeft, int lastRowCentre, int lastRowRight, int rule[]) {

	if ( rule[(lastRowLeft*4)+(lastRowCentre*2)+(lastRowRight)] == 1 )
		return 1;
	else
		return 0;
}

int calculateNextRow(int currentRow[], int rule[], int rowSize) {

	int nextRow[rowSize];

	nextRow[0] = calculateCell(currentRow[rowSize-2], currentRow[rowSize-1], 0, rule);

	for (int i=1; i<(rowSize-1); i++)
		nextRow[i] = calculateCell(currentRow[i-1], currentRow[i], currentRow[i+1], rule);

	nextRow[rowSize-1] = calculateCell(nextRow[0], nextRow[1], 0, rule);

	for (int i=0; i<rowSize; i++)
		currentRow[i] = nextRow[i];

	return 0;

}

int* decimalToBinary(int decimal) { 
    // initial array 
    static int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // length is 8 bits 
    int bit = 0; 

    // while the bit index is in this range
	// formula - > if there is no remainder then 0 would be put into the array.
	// if there is a remainder rhen 1 would be put into the array
    while (bit < 8) {
        int modulus = decimal % 2;
        int quotient = decimal / 2;
        decimal = quotient; 
        binary[bit] = modulus; 
        bit++;
    }
	
    return binary;
}

int binaryToDecimal(int rule[]) {
	int decimal = 0;

	// gets the array of binary numbers and converts them into decimal
	// formula -> eg) 01111000 (0 * 2^0) + (1 * 2^1 ) + (1 * 2^2) and so on...
	for (int i = 0; i < 8; i++) {
		decimal += rule[i] * ((int)pow(2, i));	
	}

	return decimal;
}

int rnd(void) {
	int random;
	int max = 255;
	time_t t;

	srand((unsigned) time(&t));
	random = rand() % max;

	return random;
}















