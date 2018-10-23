#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int  printRow(int row[], int rowSize) {
	for (int i=0; i<rowSize; i++)
		if (row[i] == 1)
			printf("\u2588");
		else
			printf(" ");

    return 0;
}

int calculateCell(int lastRowLeft, int lastRowCentre, int lastRowRight, int rule[]) {

	if ( rule[(lastRowLeft*4)+(lastRowCentre*2)+(lastRowRight)] == 1 )
		return 1;
	else
		return 0;

}

int calculateNextRow(int currentRow[], int rule[], int rowSize) {

	int nextRow[rowSize];

	nextRow[0] = calculateCell(0, currentRow[0], currentRow[1], rule);

	for (int i=1; i<(rowSize-1); i++)
		nextRow[i] = calculateCell(currentRow[i-1], currentRow[i], currentRow[i+1], rule);

	nextRow[rowSize-1] = calculateCell(currentRow[rowSize-2], currentRow[rowSize-1], 0, rule);

	for (int i=1; i<rowSize; i++)
		currentRow[i] = nextRow[i];

	return 0;

}

int* decimalToBinary(int decimal) { 
    // initial array 
    static int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // length is 8 bits 
    int bit = 0; 

    // while the bit index is in this range
    while (bit < 8) {
        // gives a 0 or a 1
        int modulus = decimal % 2;
        // half the decimal value each time 
        int quotient = decimal / 2;
        // set the decimal to the quotient value 
        decimal = quotient; 
        // add the modulus to the array
        binary[bit] = modulus; 
        bit++;
    }

    return binary;
}

int rnd() {
	int random;
	int max = 255;
	time_t t;

	srand((unsigned) time(&t));
	random = rand() % max;

	return random;
}

int main() {

	int *rule;
	p = decimalToBinary(rnd());

	int row[40];
	int rowSize = 40;

	for (int i=0; i<rowSize; i++)
		row[i] = 0;

	row[20] = 1;

	//int rule[] = {0,1,1,1,1,0,0,0};
	//            1 2 4 8 16 32 64 128

	printRow(row, rowSize);
	printf("\n");

	for (int i=0; i<100; i++) {
		calculateNextRow(row, rule, rowSize);
		printRow(row, rowSize);
		printf("\n");
	}
	
}
















