#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "1dca.h"

#define MAX_GEN 250
#define LENGTH 100

int main(void) {
	
	int *rule;
	int row[LENGTH];
	int rowSize = LENGTH;

	for (int i=0; i<rowSize; i++)
		row[i] = 0;

	row[rowSize/2] = 1;

	rule = decimalToBinary(rnd());
	generate(row, rowSize, rule);
	ruleInfomation(rule);
	


}

int calculateCell(int lastRowLeft, int lastRowCentre, int lastRowRight, int rule[]) {
	// eg) lastRowLeft = 1, lastRowCentre = 0, lastRowRight = 1 then if 
	// rule[5] == 1 then 1 is returned else 0 is returned
	if ( rule[(lastRowLeft*4)+(lastRowCentre*2)+(lastRowRight)] == 1 )
		return 1;
	else
		return 0;
}

void calculateNextRow(int currentRow[], int rule[], int rowSize) {
	int nextRow[rowSize];
	// wrap around when the at the 0th position in the nextRow
	nextRow[0] = calculateCell(currentRow[rowSize-1], currentRow[0], currentRow[1], rule);

	for (int i=1; i<(rowSize-1); i++)
		nextRow[i] = calculateCell(currentRow[i-1], currentRow[i], currentRow[i+1], rule);

	// wrap around whan at the i-1 position in the nextRow
	nextRow[rowSize-1] = calculateCell(currentRow[rowSize-2], currentRow[rowSize-1], currentRow[0],rule);

	// copy the memory of nextRow array to the currentRow array using the memcpy function from <string.h> library
	memcpy(currentRow, nextRow, sizeof(nextRow));
}

void paintRow(int row[], int rowSize) {

		
	// prints a white block if the arr contains 1. blank for 0
	for (int i=0; i<rowSize; i++){
		if(row[i] == 1){
			printf("\u2588");
	}else{
			printf(" ");
		}
	}
}
		

void generate(int row[], int rowSize, int rule[]) {

	for (int i = 0; i < MAX_GEN; i++) {
		paintRow(row, rowSize);
		calculateNextRow(row, rule, rowSize);
		printf("\n");
		saveTotxt(row,rowSize);

	}



}

void ruleInfomation(int rule[]) {
	printf("\n_____________________________________");
	printf("\n                                        ");
	printf("\nRule: %d", binaryToDecimal(rule));
	printf("\n");
	printf("2^n:     1  2  4  8 16 32 64 128");
	printf("\n");
	printf("Binary: ");
	for (int i = 0; i < 8; i++) {
		printf(" %d ", *(rule + i));
	}
	printf("\nGenerations: %d", MAX_GEN);
	printf("\nRow Length: %d", LENGTH);
	printf("\n_____________________________________");
	printf("\n");
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
	// returns array address
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

	// genterates a random number based on the current date and time
	// srand() is used to initialse random number generator
	srand((unsigned) time(&t)); 
	random = rand() % max;

	return random;
}

void  saveTotxt(int row[], int rowSize) {

		FILE *f = fopen("cellular.txt", "a");

			if(f==NULL){
	printf("\n File cannot be opened");

	 exit(1);
	}

	// prints a white block if the arr contains 1. blank for 0
	for (int i=0; i<rowSize; i++){

		if(row[i] == 1) {

			fprintf(f, "\u2588");
	}else{

			fprintf(f," ");
			
		}
	}
	fprintf(f,"\n");
	fclose(f);
}
		



