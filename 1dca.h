#include <stddef.h>

#define OUT_OF_BOUNDS 101
/* 
    Prints row[] contents 
    Row size needs to be the same length as the row array
*/
void paintRow(int row[], int rowSize);


/*
    Calculates the cells state depending on the rule
    lastRowLeft, lastRowCentre and lastRowRight are the positions in
    currentRow or nextRow which are defined in calculateNextRow method

    rule[] is used to determine the nextRow cells value

    Returns a 1 if rule[] == 1 ; Returns a 0 if rule[] == 0
*/
int calculateCell(int lastRowLeft, int lastRowCentre, int lastRowRight, int rule[]);


/*
    currentRow[] whis is the 0th generation to be passed through
    rule[] passed into the calculateCell function
    rowSize needs to be the same length as rule[] and currentRow[]
*/
void calculateNextRow(int currentRow[], int rule[], int rowSize);


/*
    Converts decimal value to a binary value
    Requires decimal input
    Returns a pointer to an array of the binary value
*/
int* decimalToBinary(int decimal);


/*
    Converts binary value back to decimal
    Requires and array input rule[]
    Returns decimal value
*/
int binaryToDecimal(int rule[]);

/*
    Random number generator 0 - 255
    Canot take any arguments
    Returns a random number
*/
int rnd(void);


void generate(int row[], int rowSize, int rule[]);


void ruleInfomation(int rule[]);