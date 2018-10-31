#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COLS 20
#define ROWS 20

void check(int** gen);
int** initGen(int row, int col);
void printGen(int** gen);

int main(void) {
    int i = 0;

    int** currGen = initGen(ROWS, COLS);
    currGen[ROWS/2][COLS/2] = 0;
    currGen[(ROWS/2)+1][COLS/2] = 1;
    currGen[(ROWS/2)-1][COLS/2] = 1;
    currGen[(ROWS/2)+1][(COLS/2)-1] = 1;
    // currGen[(ROWS/2)+1][(COLS/2)+1] = 1;
    // // currGen[(ROWS/2)-1][(COLS/2)-1] = 1;
    // // currGen[(ROWS/2)-1][(COLS/2)+1] = 1;
    // // currGen[ROWS/2][(COLS/2)+1] = 1;
    // // currGen[ROWS/2][(COLS/2)-1] = 1;

    printGen(currGen);

        check(currGen);
        //printGen(currGen);
        i++;
    printf("\n");

    return 0;
}

void printGen(int** gen) {
    for (int i = 1; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(gen[i][j] == 1)
                printf(" # ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

int** initGen(int row, int col) {
    int **arr = malloc(row*sizeof(int*));

    for (int i = 0; i < row; i++)
        arr[i] = malloc(sizeof(int)*col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

void check(int** gen) {
    int neighbours = 0;
    int** nextGenPtr; 

    // generate the next generation array
    nextGenPtr = initGen(ROWS, COLS);

    // outer double for loop searches the whole 2d array 
    for (int row = 1; row < 19; row++) {
        for (int col = 1; col < 19; col++) {
            
            // each element found searches for elements around the element found
            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    if ((r != 0 && c != 0) && gen[r+row][c+col] == 1)
                        neighbours++; // if an alive cell is found then its a nieghbour
                }
            }

            // if the element is 0 and the neighbors around 0 is equal to 3 then the element is born  
            if (gen[row][col] == 0) {
                if (neighbours == 3)
                    nextGenPtr[row][col] = 1;
            }
            // if the element is 1
            else if (gen[row][col] == 1) {
                // if its neighbours are 2 or 3 the element lives on
                if (neighbours == 2 || neighbours == 3)
                    nextGenPtr[row][col] = 1;
                // if there are fewer than 2 neighbours then the element dies
                else if (neighbours < 2)
                    nextGenPtr[row][col] = 0;
                // if there are greater than 3 neighbours then the element dies
                else if (neighbours > 3)
                    nextGenPtr[row][col] = 0;
            } 
        }
    }

    printGen(nextGenPtr);
    memcpy(nextGenPtr, gen, sizeof(int)*ROWS*COLS);
}


