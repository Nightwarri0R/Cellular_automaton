#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define COLS 30
#define ROWS 30
#define MAX_GEN 1000

void check(int** gen);
int** initGen(int row, int col);
void printGen(int** gen);
bool checkNeighbours(int neighbors, int** gen, int row, int col);
void generate(int** gen);
int** randomiseGen(int** gen);

int main(void) {

    int** currGen = initGen(ROWS, COLS);
    int** initialise = randomiseGen(currGen);
    printGen(initialise);
    generate(initialise);

    free(currGen);

    return 0;
}

void generate(int** gen) {
    for (int i = 0; i < MAX_GEN; i++) {
        check(gen);
        printGen(gen);
        usleep(200000);
    }
}

void printGen(int** gen) {
    for (int i = 1; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if(gen[i][j] == 1)
                printf("\u2588");
            else
                printf(" ");
        }
        printf("\n");
    }
    //printf("\n_________________________________________________________________________________________________________\n");
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

int** randomiseGen(int** gen) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            gen[i][j] = rand()%2;
    }
    return gen;
}

void check(int** gen) {
    
    int** nextgen = initGen(ROWS, COLS); 
    int neighbours;
    // outer double for loop searches the whole 2d array 
    for (int row = 1; row < ROWS-1; row++) {
        for (int col = 1; col < COLS-1; col++) {
            neighbours = 0;
            // each element found searches for elements around the element found
            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    if (gen[r+row][c+col] == 1)
                        neighbours++; // if an alive cell is found then its a neighbour  
                    //printf(" %d ", neighbours); 
                }
            }
            
             if(checkNeighbours(neighbours, gen, row, col) == true)
                    nextgen[row][col] = 1;
                else
                    nextgen[row][col] = 0;
            } 
        }

            //memcpy(gen, nextgen, sizeof(*nextgen));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            gen[i][j] = nextgen[i][j];
    }
}

bool checkNeighbours(int neighbours, int** gen, int row, int col) {
    if (gen[row][col] == 0) {
        if (neighbours == 3)
            return true;
    }
    else if (gen[row][col] == 1) {
                // if its neighbours are 2 or 3 the element lives on
        if (neighbours == 2 || neighbours == 3)
            return true;   
        else if (neighbours < 2) // if there are fewer than 2 neighbours then the element dies
            return false;
        else if (neighbours > 3) // if there are greater than 3 neighbours then the element dies
            return false;
    }

    return false;
}




